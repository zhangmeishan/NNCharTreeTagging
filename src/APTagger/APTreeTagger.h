/*
 * APTreeTagger.h
 *
 *  Created on: Jan 25, 2016
 *      Author: mszhang
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include "N3L.h"

#include "Driver.h"
#include "Options.h"
#include "Pipe.h"
#include "Utf.h"

using namespace nr;
using namespace std;


class TreeTagger {
public:
	TreeTagger(size_t memsize);
	virtual ~TreeTagger();

public:
	Driver m_driver;
	Options m_options;
	Pipe m_pipe;

public:
	int createAlphabet(const vector<Instance>& vecInsts);

public:
	void train(const string& trainFile, const string& devFile, const string& testFile, const string& modelFile, const string& optionFile);
	void predict(const Instance& input, CResult& output);
	void test(const string& testFile, const string& outputFile, const string& modelFile);

	// static training
	void getGoldActions(const vector<Instance>& vecInsts, vector<vector<CAction> >& vecActions);


public:
	void writeModelFile(const string& outputModelFile);
	void loadModelFile(const string& inputModelFile);

};

#endif /* SRC_PARSER_H_ */
