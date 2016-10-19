#ifndef SRC_HyperParams_H_
#define SRC_HyperParams_H_

#include "N3L.h"
#include "Options.h"

using namespace nr;
using namespace std;

struct HyperParams{
	//required
	int beam;
	int maxlength;
	int action_num;
	unordered_set<string> dicts;  // dictionary in order to extract iv/oov features.
	unordered_set<string> s0s1_dicts_left;
	unordered_set<string> s0s1_dicts_right;
	unordered_map<string, string> char_cat;
	unordered_map<string, unordered_map<string, int> > word_tags;
	int maxfreq;
	int threshold;


	dtype nnRegular; // for optimization
	dtype adaAlpha;  // for optimization
	dtype adaEps; // for optimization

public:
	HyperParams(){
		maxlength = 3 * max_sentence_clength + 3;
		bAssigned = false;
	}

public:
	void setRequared(Options& opt){
		//please specify diction outside
		beam = opt.beam;
		threshold = opt.threshold;
		bAssigned = true;


		nnRegular = opt.regParameter;
		adaAlpha = opt.adaAlpha;
		adaEps = opt.adaEps;
	}

	void clear(){
		bAssigned = false;
	}

	bool bValid(){
		return bAssigned;
	}


public:

	void print(){

	}

private:
	bool bAssigned;
};


#endif /* SRC_HyperParams_H_ */