/*
 * LinearTreeTagger.cpp
 *
 *  Created on: Jan 25, 2016
 *      Author: mszhang
 */

#include "LinearTreeTagger.h"
#include <set>

#include "Argument_helper.h"

TreeTagger::TreeTagger() {
	// TODO Auto-generated constructor stub
	srand(0);
	//Node::id = 0;
}

TreeTagger::~TreeTagger() {
	// TODO Auto-generated destructor stub
}

// all linear features are extracted from positive examples
int TreeTagger::createAlphabet(const vector<Instance>& vecInsts) {
	cout << "Creating Alphabet..." << endl;

	int totalInstance = vecInsts.size();

	unordered_map<string, int> word_stat;
	unordered_map<string, int> char_stat;
	unordered_map<string, set<string> > char_cat;
	unordered_map<string, unordered_map<string, int> > word_tag_stat;

	assert(totalInstance > 0);
	for (int numInstance = 0; numInstance < vecInsts.size(); numInstance++) {
		const Instance &instance = vecInsts[numInstance];
		for (int idx = 0; idx < instance.wordsize(); idx++) {
			word_stat[instance.result.words[idx]]++;
			word_tag_stat[instance.result.words[idx]][instance.result.postags[idx]]++;
		}
		int word_index = -1;
		for (int idx = 0; idx < instance.charsize(); idx++) {
			char_stat[instance.chars[idx]]++;
			if (idx == 0 || instance.result.charlabels[idx] == "b")word_index++;
			char_cat[instance.chars[idx]].insert(instance.result.postags[word_index]);
		}
	}
	word_stat[nullkey] = m_options.wordCutOff + 1;
	char_stat[nullkey] = m_options.charCutOff + 1;
	m_driver._modelparams.words.initial(word_stat, m_options.wordCutOff);
	m_driver._modelparams.chars.initial(char_stat, m_options.charCutOff);

	static unordered_map<string, int>::const_iterator elem_iter, pos_iter;
	int maxfreq = 0;
	for (elem_iter = word_stat.begin(); elem_iter != word_stat.end(); elem_iter++){
		if (elem_iter->second > maxfreq){
			maxfreq = elem_iter->second;
		}
	}
	m_driver._hyperparams.maxfreq = maxfreq;


	for (elem_iter = word_stat.begin(); elem_iter != word_stat.end(); elem_iter++){
		if (elem_iter->second > maxfreq / 5000 + m_options.threshold){
			m_driver._hyperparams.dicts.insert(elem_iter->first);
			for (pos_iter = word_tag_stat[elem_iter->first].begin(); pos_iter != word_tag_stat[elem_iter->first].end(); pos_iter++){
				m_driver._hyperparams.word_tags[elem_iter->first][pos_iter->first] = pos_iter->second;
			}
		}
	}

	static set<string>::iterator set_it;
	static string charcat;
	m_driver._modelparams.charCats.clear();
	m_driver._modelparams.charCats.from_string(nullkey);
	m_driver._modelparams.charCats.from_string(unknownkey);
	for (elem_iter = char_stat.begin(); elem_iter != char_stat.end(); elem_iter++){
		if (elem_iter->second > maxfreq / 5000 + m_options.threshold){
			charcat = "";
			for (set_it = char_cat[elem_iter->first].begin(); set_it != char_cat[elem_iter->first].end(); set_it++){
				charcat = charcat + "_" + *set_it;
			}
			charcat = charcat.substr(1);
			m_driver._hyperparams.char_cat[elem_iter->first] = charcat;
			m_driver._modelparams.charCats.from_string(charcat);
		}
	}	
	m_driver._modelparams.charCats.set_fixed_flag(true);



	unordered_map<string, int> charType_stat;
	unordered_map<string, int> subword_stat;
	unordered_map<string, int> s0s1word_head_left;
	unordered_map<string, int> s0s1word_head_right;
	unordered_map<string, unordered_map<string, int> > s0s1word_tag_stat;

	vector<CStateItem> state(m_driver._hyperparams.maxlength + 1);
	CResult output;
	CAction answer;
	Metric evalarc, evalseg, evalpos;
	int actionNum;
	evalarc.reset(); evalseg.reset(); evalpos.reset();
	for (int numInstance = 0; numInstance < totalInstance; numInstance++) {
		const Instance &instance = vecInsts[numInstance];
		actionNum = 0;
		state[actionNum].clear();
		state[actionNum].setInput(&instance.chars);
		while (!state[actionNum].IsTerminated()) {
			state[actionNum].getGoldAction(instance.result, answer);
			state[actionNum].prepare(&m_driver._hyperparams, NULL);
			charType_stat[state[actionNum]._atomFeat.str_CT0]++;
			subword_stat[state[actionNum]._atomFeat.str_s0SW]++;
			subword_stat[state[actionNum]._atomFeat.str_s1SW]++;
			subword_stat[state[actionNum]._atomFeat.str_s2SW]++;
			if (answer.isArcLeft()){
				s0s1word_head_left[state[actionNum]._atomFeat.str_s0s1SW]++;
				s0s1word_tag_stat[state[actionNum]._atomFeat.str_s0s1SW][CTag::TAG_STRING[state[actionNum]._atomFeat.sid_1WP]]++;
			}
			if (answer.isArcRight()){
				s0s1word_head_right[state[actionNum]._atomFeat.str_s0s1SW]++;
				s0s1word_tag_stat[state[actionNum]._atomFeat.str_s0s1SW][CTag::TAG_STRING[state[actionNum]._atomFeat.sid_1WP]]++;
			}
			state[actionNum].move(&(state[actionNum + 1]), answer);
			actionNum++;
		}

		state[actionNum].getResults(output);

		instance.evaluate(output, evalseg, evalpos, evalarc);

		if (!evalseg.bIdentical() || !evalpos.bIdentical() || !evalarc.bIdentical()) {
			std::cout << "error state conversion!" << std::endl;
			exit(0);
		}

		if ((numInstance + 1) % m_options.verboseIter == 0) {
			cout << numInstance + 1 << " ";
			if ((numInstance + 1) % (40 * m_options.verboseIter) == 0)
				cout << std::endl;
			cout.flush();
		}
		if (m_options.maxInstance > 0 && numInstance == m_options.maxInstance)
			break;
	}

	charType_stat[nullkey] = 1;
	m_driver._modelparams.charTypes.initial(charType_stat);
	subword_stat[nullkey] = 1;
	m_driver._modelparams.subwords.initial(subword_stat);

	for (elem_iter = s0s1word_head_left.begin(); elem_iter != s0s1word_head_left.end(); elem_iter++){
		if (elem_iter->second > maxfreq / 5000 + m_options.threshold){
			m_driver._hyperparams.s0s1_dicts_left.insert(elem_iter->first);
		}
	}

	for (elem_iter = s0s1word_head_right.begin(); elem_iter != s0s1word_head_right.end(); elem_iter++){
		if (elem_iter->second > maxfreq / 5000 + m_options.threshold){
			m_driver._hyperparams.s0s1_dicts_right.insert(elem_iter->first);
		}
	}


	cout << totalInstance << " " << endl;
	cout << "Total word num: " << word_stat.size() << endl;
	cout << "Total char num: " << char_stat.size() << endl;

	cout << "Remain word num: " << m_driver._modelparams.words.size() << endl;
	cout << "Remain char num: " << m_driver._modelparams.chars.size() << endl;
	cout << "Remain charType num: " << m_driver._modelparams.charTypes.size() << endl;


	cout << "Dictionary word num: " << m_driver._hyperparams.dicts.size() << endl;
	cout << "left head  (sub)word num: " << m_driver._hyperparams.s0s1_dicts_left.size() << endl;
	cout << "right head  (sub)word num: " << m_driver._hyperparams.s0s1_dicts_right.size() << endl;

	return 0;
}

void TreeTagger::getGoldActions(const vector<Instance>& vecInsts, vector<vector<CAction> >& vecActions){
	vecActions.clear();

	Metric evalarc, evalseg, evalpos;
	vector<CStateItem> state(m_driver._hyperparams.maxlength + 1);
	CResult output;
	CAction answer;
	evalarc.reset(); evalseg.reset(); evalpos.reset();
	static int numInstance, actionNum;
	vecActions.resize(vecInsts.size());
	for (numInstance = 0; numInstance < vecInsts.size(); numInstance++) {
		const Instance &instance = vecInsts[numInstance];

		actionNum = 0;
		state[actionNum].clear();
		state[actionNum].setInput(&instance.chars);
		while (!state[actionNum].IsTerminated()) {
			state[actionNum].getGoldAction(instance.result, answer);
			vecActions[numInstance].push_back(answer);
			state[actionNum].move(&state[actionNum + 1], answer);
			actionNum++;
		}

		state[actionNum].getResults(output);

		instance.evaluate(output, evalseg, evalpos, evalarc);

		if (!evalseg.bIdentical() || !evalpos.bIdentical() || !evalarc.bIdentical()) {
			std::cout << "error state conversion!" << std::endl;
			exit(0);
		}

		if ((numInstance + 1) % m_options.verboseIter == 0) {
			cout << numInstance + 1 << " ";
			if ((numInstance + 1) % (40 * m_options.verboseIter) == 0)
				cout << std::endl;
			cout.flush();
		}
		if (m_options.maxInstance > 0 && numInstance == m_options.maxInstance)
			break;
	}
}

void TreeTagger::train(const string& trainFile, const string& devFile, const string& testFile, const string& modelFile, const string& optionFile) {
	if (optionFile != "")
		m_options.load(optionFile);

	m_options.showOptions();
	vector<Instance> trainInsts, devInsts, testInsts;
	m_pipe.readInstances(trainFile, trainInsts, m_options.maxInstance);
	if (devFile != "")
		m_pipe.readInstances(devFile, devInsts, m_options.maxInstance);
	if (testFile != "")
		m_pipe.readInstances(testFile, testInsts, m_options.maxInstance);

	vector<vector<Instance> > otherInsts(m_options.testFiles.size());
	for (int idx = 0; idx < m_options.testFiles.size(); idx++) {
		m_pipe.readInstances(m_options.testFiles[idx], otherInsts[idx], m_options.maxInstance);
	}

	createAlphabet(trainInsts);
	m_driver._hyperparams.action_num = CAction::SEP_END;
	m_driver._hyperparams.setRequared(m_options);
	m_driver.initial();

	vector<vector<CAction> > trainInstGoldactions;
	getGoldActions(trainInsts, trainInstGoldactions);
	double bestFmeasure = 0;

	int inputSize = trainInsts.size();

	std::vector<int> indexes;
	for (int i = 0; i < inputSize; ++i)
		indexes.push_back(i);

	static Metric eval;
	static Metric metricseg_dev, metricpos_dev, metricarc_dev;
	static Metric metricseg_test, metricpos_test, metricarc_test;

	int maxIter = m_options.maxIter * (inputSize / m_options.batchSize + 1);
	int oneIterMaxRound = (inputSize + m_options.batchSize - 1) / m_options.batchSize;
	std::cout << "maxIter = " << maxIter << std::endl;
	int devNum = devInsts.size(), testNum = testInsts.size();

	static vector<CResult > decodeInstResults;
	static CResult curDecodeInst;
	static bool bCurIterBetter;
	static vector<vector<string> > subInstances;
	static vector<vector<CAction> > subInstGoldActions;

	std::cout << "Collect gold-standard features..." << std::endl;
	for (int idx = 0; idx < inputSize; idx++){
		subInstances.clear();
		subInstGoldActions.clear();
		subInstances.push_back(trainInsts[idx].chars);
		subInstGoldActions.push_back(trainInstGoldactions[idx]);
		m_driver.extractFeat(subInstances, subInstGoldActions);
		if ((idx + 1) % m_options.verboseIter == 0) {
			cout << idx + 1 << " ";
			if ((idx + 1) % (40 * m_options.verboseIter) == 0)
				cout << std::endl;
			cout.flush();
		}
	}
	cout << inputSize << std::endl;
	m_driver._modelparams.setFixed(m_options.base);

	for (int iter = 0; iter < maxIter; ++iter) {
		std::cout << "##### Iteration " << iter << std::endl;
		srand(iter);
		random_shuffle(indexes.begin(), indexes.end());
		std::cout << "random: " << indexes[0] << ", " << indexes[indexes.size() - 1] << std::endl;
		bool bEvaluate = false;

		if (m_options.batchSize == 1){
			eval.reset();
			bEvaluate = true;
			for (int idy = 0; idy < inputSize; idy++) {
				subInstances.clear();
				subInstGoldActions.clear();
				subInstances.push_back(trainInsts[indexes[idy]].chars);
				subInstGoldActions.push_back(trainInstGoldactions[indexes[idy]]);
				double cost = m_driver.train(subInstances, subInstGoldActions);

				eval.overall_label_count += m_driver._eval.overall_label_count;
				eval.correct_label_count += m_driver._eval.correct_label_count;

				if ((idy + 1) % (m_options.verboseIter * 10) == 0) {
					std::cout << "current: " << idy + 1 << ", Cost = " << cost << ", Correct(%) = " << eval.getAccuracy() << std::endl;
				}
				m_driver.updateModel();
			}
			std::cout << "current: " << iter + 1 << ", Correct(%) = " << eval.getAccuracy() << std::endl;
		}
		else{
			if (iter == 0)eval.reset();
			subInstances.clear();
			subInstGoldActions.clear();
			for (int idy = 0; idy < m_options.batchSize; idy++) {
				subInstances.push_back(trainInsts[indexes[idy]].chars);
				subInstGoldActions.push_back(trainInstGoldactions[indexes[idy]]);
			}
			double cost = m_driver.train(subInstances, subInstGoldActions);

			eval.overall_label_count += m_driver._eval.overall_label_count;
			eval.correct_label_count += m_driver._eval.correct_label_count;

			if ((iter + 1) % (m_options.verboseIter) == 0) {
				std::cout << "current: " << iter + 1 << ", Cost = " << cost << ", Correct(%) = " << eval.getAccuracy() << std::endl;
				eval.reset();
				bEvaluate = true;
			}

			m_driver.updateModel();
		}

		if (bEvaluate && devNum > 0) {
			bCurIterBetter = false;
			if (!m_options.outBest.empty())
				decodeInstResults.clear();
			metricseg_dev.reset(); metricpos_dev.reset(); metricarc_dev.reset(); 
			for (int idx = 0; idx < devInsts.size(); idx++) {
				predict(devInsts[idx], curDecodeInst);
				devInsts[idx].evaluate(curDecodeInst, metricseg_dev, metricpos_dev, metricarc_dev);
				if (!m_options.outBest.empty()) {
					decodeInstResults.push_back(curDecodeInst);
				}
			}
			std::cout << "dev:" << std::endl;
			metricseg_dev.print();
			metricpos_dev.print();
			metricarc_dev.print();

			if (!m_options.outBest.empty() && metricpos_dev.getAccuracy() > bestFmeasure) {
				m_pipe.outputAllInstances(devFile + m_options.outBest, decodeInstResults);
				bCurIterBetter = true;
			}


			if (testNum > 0) {
				if (!m_options.outBest.empty())
					decodeInstResults.clear();
				metricseg_test.reset(); metricpos_test.reset(); metricarc_test.reset();
				for (int idx = 0; idx < testInsts.size(); idx++) {
					predict(testInsts[idx], curDecodeInst);
					testInsts[idx].evaluate(curDecodeInst, metricseg_test, metricpos_test, metricarc_test);
					if (bCurIterBetter && !m_options.outBest.empty()) {
						decodeInstResults.push_back(curDecodeInst);
					}
				}
				std::cout << "test:" << std::endl;
				metricseg_test.print();
				metricpos_test.print();
				metricarc_test.print();

				if (!m_options.outBest.empty() && bCurIterBetter) {
					m_pipe.outputAllInstances(testFile + m_options.outBest, decodeInstResults);
				}
			}

			for (int idx = 0; idx < otherInsts.size(); idx++) {
				std::cout << "processing " << m_options.testFiles[idx] << std::endl;
				if (!m_options.outBest.empty())
					decodeInstResults.clear();
				metricseg_test.reset(); metricpos_test.reset(); metricarc_test.reset();
				for (int idy = 0; idy < otherInsts[idx].size(); idy++) {
					predict(otherInsts[idx][idy], curDecodeInst);
					otherInsts[idx][idy].evaluate(curDecodeInst, metricseg_test, metricpos_test, metricarc_test);
					if (bCurIterBetter && !m_options.outBest.empty()) {
						decodeInstResults.push_back(curDecodeInst);
					}
				}
				std::cout << "test:" << std::endl;
				metricseg_test.print();
				metricpos_test.print();
				metricarc_test.print();

				if (!m_options.outBest.empty() && bCurIterBetter) {
					m_pipe.outputAllInstances(m_options.testFiles[idx] + m_options.outBest, decodeInstResults);
				}
			}


			if (m_options.saveIntermediate && metricpos_dev.getAccuracy() > bestFmeasure) {
				std::cout << "Exceeds best previous DIS of " << bestFmeasure << ". Saving model file.." << std::endl;
				bestFmeasure = metricpos_dev.getAccuracy();
				writeModelFile(modelFile);
			}
		}
	}
}

void TreeTagger::predict(const Instance& input, CResult& output) {
	m_driver.decode(input.chars, output);
}

void TreeTagger::test(const string& testFile, const string& outputFile, const string& modelFile) {
	loadModelFile(modelFile);
	vector<Instance> testInsts;
	m_pipe.readInstances(testFile, testInsts, m_options.maxInstance);

	vector<CResult > testInstResults(testInsts.size());
	Metric metricseg_test, metricpos_test, metricarc_test;
	metricseg_test.reset(); metricpos_test.reset(); metricarc_test.reset();
	for (int idx = 0; idx < testInsts.size(); idx++) {
		vector<string> result_labels;
		predict(testInsts[idx], testInstResults[idx]);
		testInsts[idx].evaluate(testInstResults[idx], metricseg_test, metricpos_test, metricarc_test);
	}
	std::cout << "test:" << std::endl;
	metricseg_test.print();
	metricpos_test.print();
	metricarc_test.print();

	std::ofstream os(outputFile.c_str());
	static int word_index;
	for (int idx = 0; idx < testInsts.size(); idx++) {
		word_index = -1;
		for (int idy = 0; idy < testInstResults[idx].charsize(); idy++){
			if (idy == 0 || testInstResults[idx].charlabels[idy] == "b"){
				word_index++;
			}
			os << (*testInstResults[idx].chars)[idy] << " " << testInstResults[idx].postags[word_index] << " " << testInstResults[idx].charlabels[idy]
				<< " " << testInstResults[idx].charheads[idy];
			if (testInstResults[idx].charheads[idy] < 0){
				os << " ROOT out" << std::endl;
			}
			else{
				os << " -NONE- in" << std::endl;
			}
		}
		os << std::endl;
	}
	os.close();
}


void TreeTagger::loadModelFile(const string& inputModelFile) {

}

void TreeTagger::writeModelFile(const string& outputModelFile) {

}

int main(int argc, char* argv[]) {
	std::string trainFile = "", devFile = "", testFile = "", modelFile = "";
	std::string wordEmbFile = "", optionFile = "";
	std::string outputFile = "";
	bool bTrain = false;
	dsr::Argument_helper ah;

	ah.new_flag("l", "learn", "train or test", bTrain);
	ah.new_named_string("train", "trainCorpus", "named_string", "training corpus to train a model, must when training", trainFile);
	ah.new_named_string("dev", "devCorpus", "named_string", "development corpus to train a model, optional when training", devFile);
	ah.new_named_string("test", "testCorpus", "named_string",
		"testing corpus to train a model or input file to test a model, optional when training and must when testing", testFile);
	ah.new_named_string("model", "modelFile", "named_string", "model file, must when training and testing", modelFile);
	ah.new_named_string("word", "wordEmbFile", "named_string", "pretrained word embedding file to train a model, optional when training", wordEmbFile);
	ah.new_named_string("option", "optionFile", "named_string", "option file to train a model, optional when training", optionFile);
	ah.new_named_string("output", "outputFile", "named_string", "output file to test, must when testing", outputFile);

	ah.process(argc, argv);

	TreeTagger segmentor;
	if (bTrain) {
		segmentor.train(trainFile, devFile, testFile, modelFile, optionFile);
	}
	else {
		segmentor.test(testFile, outputFile, modelFile);
	}

	//test(argv);
	//ah.write_values(std::cout);

}
