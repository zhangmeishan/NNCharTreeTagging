/*
 * CResult.h
 *
 *  Created on: June 5, 2016
 *      Author: PanDa
 */

#ifndef BASIC_CRESULT_H_
#define BASIC_CRESULT_H_

#include <string>
#include <vector>
#include <fstream>
#include "N3L.h"
#include "Alphabet.h"
#include "Utf.h"

using namespace std;

class CResult {
public:
	vector<string> words;
	vector<string> postags;
	vector<int> charheads;
	vector<string> charlabels;

	const vector<string>* chars;
public:

	inline void clear() {
		chars = NULL;
		words.clear();
		postags.clear();
		charheads.clear();
		charlabels.clear();
	}

	inline void allocate(const int& wsize, const int& csize) {
		//chars = NULL;
		if (words.size() != wsize || charheads.size() != csize){
			words.resize(wsize);
			postags.resize(wsize);
			charheads.resize(csize);
			charlabels.resize(csize);
		}
	}

	inline int wordsize() const {
		return words.size();
	}

	inline int charsize() const {
		return charheads.size();
	}

	inline int& head(int idx){
		return charheads[idx];
	}

	inline std::string& word(int idx){
		return words[idx];
	}

	inline std::string& tag(int idx){
		return postags[idx];
	}

	inline std::string& charlabel(int idx){
		return charlabels[idx];
	}

	inline const std::string& charc(int idx) const{
		return (*chars)[idx];
	}


	inline void copyValuesFrom(const CResult& result) {
		static int wsize, csize;
		wsize = result.wordsize();
		csize = result.charsize();
		allocate(wsize, csize);

		for (int i = 0; i < wsize; i++) {
			words[i] = result.words[i];
			postags[i] = result.postags[i];
		}
		for (int i = 0; i < csize; i++) {
			charheads[i] = result.charheads[i];
			charlabels[i] = result.charlabels[i];
		}
		chars = result.chars;
	}

	inline void copyValuesFrom(const CResult& result, const vector<string>* pchars) {
		static int wsize, csize;
		wsize = result.wordsize();
		csize = result.charsize();
		allocate(wsize, csize);

		for (int i = 0; i < wsize; i++) {
			words[i] = result.words[i];
			postags[i] = result.postags[i];
		}
		for (int i = 0; i < csize; i++) {
			charheads[i] = result.charheads[i];
			charlabels[i] = result.charlabels[i];
		}
		chars = pchars;
	}

	inline void extractWS(unordered_set<string>& arcIndexes) const {
		arcIndexes.clear();
		int idx = 0, idy = 0;
		string curWord = "";
		int beginId = 0;
		static int wsize, csize;
		wsize = wordsize();
		csize = charsize();
		while (idx < csize && idy < wsize) {
			curWord = curWord + charc(idx);
			if (curWord.length() == words[idy].length()) {
				stringstream ss;
				ss << "[" << beginId << "," << idx << "]";
				for (int idz = beginId; idz <= idx; idz++){
					ss << "(" << idz << "," << charheads[idz] << ")";
				}
				arcIndexes.insert(ss.str());
				idy++;
				beginId = idx + 1;
				curWord = "";
			}
			idx++;
		}

		if (idx != csize || idy != wsize) {
			std::cout << "error results, please check" << std::endl;
		}
	}

	inline void extractSEG(unordered_set<string>& segIndexes) const {
		segIndexes.clear();
		int idx = 0, idy = 0;
		string curWord = "";
		int beginId = 0;
		static int wsize, csize;
		wsize = wordsize();
		csize = charsize();
		while (idx < csize && idy < wsize) {
			curWord = curWord + charc(idx);
			if (curWord.length() == words[idy].length()) {
				stringstream ss;
				ss << "[" << beginId << "," << idx << "]";
				segIndexes.insert(ss.str());
				idy++;
				beginId = idx + 1;
				curWord = "";
			}
			idx++;
		}

		if (idx != csize || idy != wsize) {
			std::cout << "error results, please check" << std::endl;
		}
	}

	inline void extractPOS(unordered_set<string>& posIndexes) const {
		posIndexes.clear();
		int idx = 0, idy = 0;
		string curWord = "";
		int beginId = 0;
		static int wsize, csize;
		wsize = wordsize();
		csize = charsize();
		while (idx < csize && idy < wsize) {
			curWord = curWord + charc(idx);
			if (curWord.length() == words[idy].length()) {
				stringstream ss;
				ss << "[" << beginId << "," << idx << "]" << postags[idy];
				posIndexes.insert(ss.str());
				idy++;
				beginId = idx + 1;
				curWord = "";
			}
			idx++;
		}

		if (idx != csize || idy != wsize) {
			std::cout << "error results, please check" << std::endl;
		}
	}

};

#endif
