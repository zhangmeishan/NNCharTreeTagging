/*
 * State.h
 *
 *  Created on: Oct 1, 2015
 *      Author: mszhang
 */

#ifndef TAGGER_STATE_H_
#define TAGGER_STATE_H_

#include "ModelParams.h"
#include "Action.h"
#include "ActionedNodes.h"
#include "AtomFeatures.h"
#include "Utf.h"
#include "Instance.h"

class CStateItem {
public:
	//values
	string _word;
	short _wstart;
	short _wend;
	short _wspan;
	short _tag;
	short _stack[max_sentence_clength];
	short _stacksize;
	short _head[max_sentence_clength];
	short _left_most_index[max_sentence_clength]; // relative position
	short _right_most_index[max_sentence_clength]; // relative position
	short _next_index;
	short _step;

	CStateItem *_prevStackState;
	CStateItem *_prevState;

	const std::vector<std::string> *_chars;
	int _char_size;
	int _word_count;

	// features
	ActionedNodes _nextscores;  // features current used
	AtomFeatures _atomFeat;  //features will be used for future
	CAction _lastAction;
	PNode _score;

public:
	bool _bStart; // whether it is a start state
	bool _bGold; // for train


public:
	CStateItem() {
		clear();
	}


	virtual ~CStateItem(){
		clear();
	}

	void initial(ModelParams& params, HyperParams& hyparams) {
		for (int idx = 0; idx < CAction::SEP_END; idx++){
			_nextscores.initial(params, hyparams);
		}
	}

	void setInput(const std::vector<std::string>* chars) {
		_chars = chars;
		_char_size = chars->size();
	}

	void clear() {
		_word = "";
		_wstart = -1;
		_wend = -1;
		_tag = -1;
		_wspan = -1;

		_stacksize = 0;
		_stack[_stacksize] = -2;

		_next_index = 0;
		_head[_next_index] = -2;
		_left_most_index[_next_index] = -2;
		_right_most_index[_next_index] = -2;

		_prevStackState = 0;
		_prevState = 0;

		_lastAction.clear();
		_word_count = 0;

		_chars = 0;
		_char_size = 0;

		_score = NULL;
		_bStart = true;
		_bGold = true;
		_step = 0;
	}


	const CStateItem* getPrevStackState() const{
		return _prevStackState;
	}

	const CStateItem* getPrevState() const{
		return _prevState;
	}


public:
	//only assign context
	void separate(CStateItem* next, int tag){
		if (_next_index >= _char_size || _stacksize > 1) {
			std::cout << "separate error" << std::endl;
			return;
		}
		next->_word = (*_chars)[_next_index];
		next->_wstart = _next_index;
		next->_wend = _next_index;
		next->_tag = tag;
		next->_wspan = 1;

		next->_stack[0] = _next_index;
		next->_stack[1] = -2;
		next->_stacksize = 1;


		memcpy(next->_head, _head, sizeof(short)*_next_index);
		next->_head[_next_index] = next->_head[_next_index + 1] = -1;
		memcpy(next->_left_most_index, _left_most_index, sizeof(short)*_next_index);
		memcpy(next->_right_most_index, _right_most_index, sizeof(short)*_next_index);
		next->_left_most_index[_next_index] = next->_right_most_index[_next_index] = _next_index;
		next->_left_most_index[_next_index + 1] = next->_right_most_index[_next_index + 1] = -2;

		next->_prevStackState = this;
		next->_prevState = this;
		next->_next_index = _next_index + 1;

		next->_chars = _chars;
		next->_char_size = _char_size;

		next->_word_count = _word_count + 1;
		next->_lastAction.set(CAction::SEP + tag);
	}

	void append(CStateItem* next){
		if (_next_index >= _char_size || _next_index == 0) {
			std::cout << "append error" << std::endl;
			return;
		}
		next->_word = _word + (*_chars)[_next_index];
		next->_wstart = _wstart;
		next->_wend = _next_index;
		next->_tag = _tag;
		next->_wspan = _wspan + 1;

		memcpy(next->_stack, _stack, sizeof(short)*_stacksize);
		next->_stack[_stacksize] = _next_index;
		next->_stack[_stacksize+1] = -2;
		next->_stacksize = _stacksize + 1;

		memcpy(next->_head, _head, sizeof(short)*_next_index);
		next->_head[_next_index] = next->_head[_next_index + 1] = -1;
		memcpy(next->_left_most_index, _left_most_index, sizeof(short)*_next_index);
		memcpy(next->_right_most_index, _right_most_index, sizeof(short)*_next_index);
		next->_left_most_index[_next_index] = next->_right_most_index[_next_index] = _next_index;
		next->_left_most_index[_next_index + 1] = next->_right_most_index[_next_index + 1] = -2;

		next->_prevStackState = _prevStackState;
		next->_prevState = this;
		next->_next_index = _next_index + 1;

		next->_chars = _chars;
		next->_char_size = _char_size;

		next->_word_count = _word_count;
		next->_lastAction.set(CAction::APP);
	}

	void arc_left(CStateItem* next){
		if (_stacksize < 2) {
			std::cout << "arc left error" << std::endl;
			return;
		}
		next->_word = _word;
		next->_wstart = _wstart;
		next->_wend = _wend;
		next->_tag = _tag;
		next->_wspan = _wspan;
		static short top0, top1;
		top0 = _stack[_stacksize - 1];
		top1 = _stack[_stacksize - 2];

		memcpy(next->_stack, _stack, sizeof(short)* (_stacksize - 2));
		next->_stack[_stacksize - 2] = top0;
		next->_stack[_stacksize - 1] = -2;
		next->_stacksize = _stacksize - 1;

		memcpy(next->_head, _head, sizeof(short)*_next_index);
		next->_head[top1] = top0;
		memcpy(next->_left_most_index, _left_most_index, sizeof(short)*_next_index);
		memcpy(next->_right_most_index, _right_most_index, sizeof(short)*_next_index);
		next->_left_most_index[top0] = top1;

		next->_prevStackState = _prevStackState;
		next->_prevState = this;
		next->_next_index = _next_index;

		next->_chars = _chars;
		next->_char_size = _char_size;

		next->_word_count = _word_count;
		next->_lastAction.set(CAction::ARCLEFT);
	}

	void arc_right(CStateItem* next){
		if (_stacksize < 2) {
			std::cout << "arc left error" << std::endl;
			return;
		}
		next->_word = _word;
		next->_wstart = _wstart;
		next->_wend = _wend;
		next->_tag = _tag;
		next->_wspan = _wspan;
		static short top0, top1;
		top0 = _stack[_stacksize - 1];
		top1 = _stack[_stacksize - 2];

		memcpy(next->_stack, _stack, sizeof(short)* (_stacksize - 2));
		next->_stack[_stacksize - 2] = top1;
		next->_stack[_stacksize - 1] = -2;
		next->_stacksize = _stacksize - 1;

		memcpy(next->_head, _head, sizeof(short)*_next_index);
		next->_head[top0] = top1;
		memcpy(next->_left_most_index, _left_most_index, sizeof(short)*_next_index);
		memcpy(next->_right_most_index, _right_most_index, sizeof(short)*_next_index);
		next->_right_most_index[top1] = top0;

		next->_prevStackState = _prevStackState;
		next->_prevState = this;
		next->_next_index = _next_index;

		next->_chars = _chars;
		next->_char_size = _char_size;

		next->_word_count = _word_count;
		next->_lastAction.set(CAction::ARCRIGHT);
	}

	//only assign context
	void finish(CStateItem* next){
		if (_next_index != _char_size) {
			std::cout << "finish error" << std::endl;
			return;
		}
		next->_word = "";
		next->_wstart = -1;
		next->_wend = -1;
		next->_tag = -1;
		next->_wspan = 0;

		next->_stack[0] = -2;
		next->_stacksize = 0;

		memcpy(next->_head, _head, sizeof(short)*_next_index);
		next->_head[_next_index] = next->_head[_next_index + 1] = -2;
		memcpy(next->_left_most_index, _left_most_index, sizeof(short)*_next_index);
		memcpy(next->_right_most_index, _right_most_index, sizeof(short)*_next_index);
		next->_left_most_index[_next_index] = next->_right_most_index[_next_index] = -2;
		next->_left_most_index[_next_index + 1] = next->_right_most_index[_next_index + 1] = -2;

		next->_prevStackState = this;
		next->_prevState = this;
		next->_next_index = _next_index + 1;

		next->_chars = _chars;
		next->_char_size = _char_size;

		next->_word_count = _word_count;
		next->_lastAction.set(CAction::FIN);
	}

	void idle(CStateItem* next){
		if (!IsTerminated()) {
			std::cout << "idle error" << std::endl;
			return;
		}
		next->_word = "";
		next->_wstart = -1;
		next->_wend = -1;
		next->_tag = -1;
		next->_wspan = 0;

		next->_stack[0] = -2;
		next->_stacksize = 0;

		memcpy(next->_head, _head, sizeof(short)*_next_index);
		next->_head[_next_index] = next->_head[_next_index + 1] = -2;
		memcpy(next->_left_most_index, _left_most_index, sizeof(short)*_next_index);
		memcpy(next->_right_most_index, _right_most_index, sizeof(short)*_next_index);
		next->_left_most_index[_next_index] = next->_right_most_index[_next_index] = -2;
		next->_left_most_index[_next_index + 1] = next->_right_most_index[_next_index + 1] = -2;

		next->_prevStackState = _prevStackState;
		next->_prevState = this;
		next->_next_index = _next_index;

		next->_chars = _chars;
		next->_char_size = _char_size;

		next->_word_count = _word_count;
		next->_lastAction.set(CAction::IDLE);
	}



	void move(CStateItem* next, const CAction& ac){
		if (ac.isAppend()) {
			append(next);
		}
		else if (ac.isSeparate()) {
			separate(next, ac.getTAGId());
		}
		else if (ac.isArcLeft()) {
			arc_left(next);
		}
		else if (ac.isArcRight()) {
			arc_right(next);
		}
		else if (ac.isFinish()) {
			finish(next);
		}
		else if (ac.isIdle()) {
			idle(next);
		}
		else {
			std::cout << "error action" << std::endl;
		}

		next->_bStart = false;
		next->_bGold = false;
		next->_step = _step + 1;		
	}

	bool IsTerminated() const {
		if (_lastAction.isFinish() || _lastAction.isIdle())
			return true;
		return false;
	}

	//partial results
	void getResults(CResult& result) const {
		result.clear();
		static vector<const CStateItem *> preSepStates;
		preSepStates.clear();
		if (!IsTerminated()){
			preSepStates.insert(preSepStates.begin(), this);
		}
		const CStateItem *prevStackState = _prevStackState;
		while (prevStackState != 0 && !prevStackState->_bStart) {
			preSepStates.insert(preSepStates.begin(), prevStackState);
			prevStackState = prevStackState->_prevStackState;
		}
		//will add results
		static int state_num;
		state_num = preSepStates.size();
		if (state_num != _word_count){
			std::cout << "bug exists: " << state_num << " " << _word_count << std::endl;
		}
		for (int idx = 0; idx < state_num; idx++){
			result.words.push_back(preSepStates[idx]->_word);
			result.postags.push_back(CTag::TAG_STRING[preSepStates[idx]->_tag]);
			result.charlabels.push_back("b");
			for (int idy = preSepStates[idx]->_wstart + 1; idy <= preSepStates[idx]->_wend; idy++){
				result.charlabels.push_back("i");
			}
		}

		for (int idx = 0; idx < _next_index && idx < _char_size; idx++){
			result.charheads.push_back(_head[idx]);
		}
		result.chars = _chars;
	}


	void getGoldAction(const CResult& result, CAction& ac) const {
		static int top0, top1, word_length;
		static bool has_right_child;
		static string curTag;
		if (_next_index == _char_size) {
			if (_stacksize == 1){
				ac.set(CAction::FIN);
				return;
			}
			else{
				top0 = _stack[_stacksize - 1];
				top1 = _stack[_stacksize - 2];
				if (result.charheads[top0] == top1) {
					ac.set(CAction::ARCRIGHT);
					return;
				}
				else if (result.charheads[top1] == top0){
					ac.set(CAction::ARCLEFT);
					return;
				}
				else{
					std::cout << "Get gold action: error here" << std::endl;
				}
			}
		}

		if (_next_index == 0) {
			curTag = result.postags[_word_count];
			ac.set(CAction::SEP + CTag::getID(curTag));
			return;
		}

		if (_next_index > 0 && _next_index < _char_size) {
			// should have a check here to see whether the words are match, but I did not do it here
			word_length = getUTF8StringLength(result.words[_word_count - 1]);
			if (_wspan == word_length) {
				if (_stacksize == 1){
					curTag = result.postags[_word_count];
					ac.set(CAction::SEP + CTag::getID(curTag));
					return;
				}
				else{
					top0 = _stack[_stacksize - 1];
					top1 = _stack[_stacksize - 2];
					if (result.charheads[top0] == top1) {
						ac.set(CAction::ARCRIGHT);
						return;
					}
					else if (result.charheads[top1] == top0){
						ac.set(CAction::ARCLEFT);
						return;
					}
					else{
						std::cout << "Get gold action: error here" << std::endl;
					}
				}
			}
			else if (_wspan < word_length) {
				if (_stacksize == 1){
					ac.set(CAction::APP);
					return;
				}
				else{
					top0 = _stack[_stacksize - 1];
					top1 = _stack[_stacksize - 2];

					has_right_child = false;
					for (int i = _next_index; i < _wstart + word_length; ++i) {
						if (result.charheads[i] == top0) { has_right_child = true; break; }
					}
					if (result.charheads[top0] == top1 && !has_right_child) {
						ac.set(CAction::ARCRIGHT);
						return;
					}
					else if (result.charheads[top1] == top0){
						ac.set(CAction::ARCLEFT);
						return;
					}
					else{
						ac.set(CAction::APP);
						return;
					}
				}
			}
			else{

			}
		}

		ac.set(CAction::NO_ACTION);
		return;
	}

	// we did not judge whether history actions are match with current state.
	void getGoldAction(const CStateItem* goldState, CAction& ac) const{
		if (_step > goldState->_step || _step < 0) {
			ac.set(CAction::NO_ACTION);
			return;
		}
		const CStateItem *prevState = goldState->_prevState;
		CAction curAction = goldState->_lastAction;
		while (_step < prevState->_step) {
			curAction = prevState->_lastAction;
			prevState = prevState->_prevState;
		}
		return ac.set(curAction._code);
	}

	void getCandidateActions(vector<CAction> & actions) const{
		actions.clear();
		static CAction ac;
		if (IsTerminated()){
			ac.set(CAction::IDLE);
			actions.push_back(ac);
			return;
		}
		if (_next_index == 0){
			for (int idx = 0; idx < CTag::TAG_SIZE; idx++){
				ac.set(CAction::SEP + idx);
				actions.push_back(ac);
			}
		}
		else if (_next_index == _char_size){
			if (_stacksize == 1){
				ac.set(CAction::FIN);
				actions.push_back(ac);
			}
			else if (_stacksize > 1){
				ac.set(CAction::ARCLEFT);
				actions.push_back(ac);
				ac.set(CAction::ARCRIGHT);
				actions.push_back(ac);
			}
		}
		else if (_next_index > 0 && _next_index < _char_size){
			if (_stacksize == 1){
				for (int idx = 0; idx < CTag::TAG_SIZE; idx++){
					ac.set(CAction::SEP + idx);
					actions.push_back(ac);
				}
				ac.set(CAction::APP);
				actions.push_back(ac);
			}
			else if (_stacksize > 1){
				ac.set(CAction::ARCLEFT);
				actions.push_back(ac);
				ac.set(CAction::ARCRIGHT);
				actions.push_back(ac);
				ac.set(CAction::APP);
				actions.push_back(ac);
			}
		}
		else{

		}

	}

	inline std::string str() const{
		stringstream curoutstr;
		curoutstr << "score: " << _score->val(0, 0) << " ";
		curoutstr << "seg:";
		static CResult result;
		getResults(result);
		for (int idx = 0; idx < _word_count; idx++){
			curoutstr << " " << result.words[idx] << "_" << result.postags[idx];
		}

		return curoutstr.str();
	}


public:
	inline void computeNextScore(Graph *cg, const vector<CAction>& acs){
		if (_bStart){
			_nextscores.forward(cg, acs, _atomFeat, NULL);
		}
		else{
			_nextscores.forward(cg, acs, _atomFeat, _score);
		}
	}

	inline void collectFeat(ModelParams* model_params){
		_prevState->_atomFeat.collectFeatures(_lastAction, model_params);
	}

	inline void prepare(HyperParams* hyper_params, ModelParams* model_params){
		//basic features
		static int idx, length, p1wstart, p1wend;
		static string lastTag;
		_atomFeat.str_C0 = _next_index < _char_size ? _chars->at(_next_index) : nullkey;
		_atomFeat.str_1C = _next_index > 0 && _next_index - 1 < _char_size ? _chars->at(_next_index - 1) : nullkey;
		_atomFeat.str_2C = _next_index > 1 && _next_index - 2 < _char_size ? _chars->at(_next_index - 2) : nullkey;

		_atomFeat.str_CT0 = _next_index < _char_size ? wordtype(_atomFeat.str_C0) : nullkey;
		_atomFeat.str_1CT = _next_index > 0 && _next_index - 1 < _char_size ? wordtype(_atomFeat.str_1C) : nullkey;
		_atomFeat.str_2CT = _next_index > 1 && _next_index - 2 < _char_size ? wordtype(_atomFeat.str_2C) : nullkey;

		_atomFeat.str_CC0 = _next_index < _char_size ? (hyper_params->char_cat.find(_atomFeat.str_C0) != hyper_params->char_cat.end() ? hyper_params->char_cat[_atomFeat.str_C0] : unknownkey) : nullkey;
		_atomFeat.str_1CC = _next_index > 0 && _next_index - 1 < _char_size ? (hyper_params->char_cat.find(_atomFeat.str_1C) != hyper_params->char_cat.end() ? hyper_params->char_cat[_atomFeat.str_1C] : unknownkey) : nullkey;

		_atomFeat.str_1W = _wend == -1 ? nullkey : _word;
		_atomFeat.str_1Wc0 = _wend == -1 ? nullkey : _chars->at(_wstart);

		_atomFeat.sid_1WD = _wend == -1 ? 0 : (hyper_params->dicts.find(_atomFeat.str_1W) != hyper_params->dicts.end() ? 1 : 2);
		
		{
			length = _wend - _wstart + 1;
			if (length > 5)
				length = 5;
			_atomFeat.sid_1WL = _wend == -1 ? 0 : length;
		}

		if (_wend == -1){
			_atomFeat.str_1Wci.clear();
		}
		else{
			_atomFeat.str_1Wci.clear();
			for (int idx = _wstart; idx < _wend; idx++){
				_atomFeat.str_1Wci.push_back(_chars->at(idx));
			}
		}


		p1wstart = _prevStackState == 0 ? -1 : _prevStackState->_wstart;
		p1wend = _prevStackState == 0 ? -1 : _prevStackState->_wend;
		_atomFeat.str_2W = p1wend == -1 ? nullkey : _prevStackState->_word;
		_atomFeat.str_2Wc0 = p1wend == -1 ? nullkey : _chars->at(p1wstart);
		_atomFeat.str_2Wcn = p1wend == -1 ? nullkey : _chars->at(p1wend);
		{
			length = p1wend - p1wstart + 1;
			if (length > 5)
				length = 5;
			_atomFeat.sid_2WL = p1wend == -1 ? 0 : length;
		}

		//additional features for POS Tagging
		_atomFeat.sid_1WP = _wend == -1 ? (CTag::TAG_SIZE) : _tag;
		_atomFeat.sid_2WP = p1wend == -1 ? (CTag::TAG_SIZE) : _prevStackState->_tag;

		//
		static int top0, top1, top2;
		static int top0_start, top1_start, top2_start, top0_end, top1_end, top2_end;
		_atomFeat.str_s0SW = nullkey;
		_atomFeat.str_s1SW = nullkey;
		_atomFeat.str_s2SW = nullkey;
		_atomFeat.str_s0SWhc = nullkey;
		_atomFeat.str_s1SWhc = nullkey;
		_atomFeat.str_s2SWhc = nullkey;
		_atomFeat.sid_s0t = CTag::TAG_SIZE;
		_atomFeat.str_1Whc = nullkey;
		_atomFeat.str_2Whc = nullkey;
		_atomFeat.str_s0s1SW = nullkey;
		if (_stacksize > 1){
			top0 = _stack[_stacksize - 1];
			top0_start = _left_most_index[top0];
			top0_end = _right_most_index[top0];
			_atomFeat.str_s0SW = "";
			for (idx = top0_start; idx <= top0_end; idx++){
				_atomFeat.str_s0SW = _atomFeat.str_s0SW + _chars->at(idx);
			}

			top1 = _stack[_stacksize - 2];
			top1_start = _left_most_index[top1];  // top1_end + 1 should equal top0_start;
			top1_end = _right_most_index[top1];
			//assert(top1_end + 1 == top0_start);
			_atomFeat.str_s1SW = "";
			for (idx = top1_start; idx <= top1_end; idx++){
				_atomFeat.str_s1SW = _atomFeat.str_s1SW + _chars->at(idx);
			}

			_atomFeat.str_s0s1SW = _atomFeat.str_s1SW + _atomFeat.str_s0SW;
			_atomFeat.sid_s0s1SWL = top0_end - top1_start + 1;
			if (_atomFeat.sid_s0s1SWL > 5)_atomFeat.sid_s0s1SWL = 5;

			_atomFeat.str_s0SWhc = _chars->at(top0);
			_atomFeat.str_s1SWhc = _chars->at(top1);
			_atomFeat.sid_s0t = _atomFeat.sid_1WP;
			if (_stacksize > 2){
				top2 = _stack[_stacksize - 3];
				top2_start = _left_most_index[top2];  // top2_end + 1 should equal top1_start;
				top2_end = _right_most_index[top2];
				//assert(top2_end + 1 == top1_start);
				_atomFeat.str_s2SW = "";
				for (idx = top2_start; idx <= top2_end; idx++){
					_atomFeat.str_s2SW = _atomFeat.str_s2SW + _chars->at(idx);
				}
				_atomFeat.str_s2SWhc = _chars->at(top2);
			}
		}
		else if (_stacksize == 1){
			top0 = _stack[_stacksize - 1];
			_atomFeat.str_1Whc = _chars->at(top0);
			if (p1wend >= 0){
				//_prevStackState->_stacksize must be 1
				//assert(_prevStackState->_stacksize == 1);
				top1 = _prevStackState->_stack[0];
				_atomFeat.str_2Whc = _chars->at(top1);
			}

		}
		else{
			//should be the first step, or finish step
		}

		_atomFeat.sid_s0s1arcl = _atomFeat.sid_s0s1arcr = 0;
		_atomFeat.sid_s0s1SWD = 0;
		if (_stacksize > 1){
			if (hyper_params->s0s1_dicts_left.find(_atomFeat.str_s0s1SW) != hyper_params->s0s1_dicts_left.end()
				|| hyper_params->s0s1_dicts_right.find(_atomFeat.str_s0s1SW) != hyper_params->s0s1_dicts_right.end()){
				_atomFeat.sid_s0s1SWD = 1;
			}
			else{
				_atomFeat.sid_s0s1SWD = 2; // contain this sub word
			}

			if (hyper_params->s0s1_dicts_left.find(_atomFeat.str_s0s1SW) != hyper_params->s0s1_dicts_left.end()){
				_atomFeat.sid_s0s1arcl = 1;
			}
			else{
				_atomFeat.sid_s0s1arcl = 2;
			}

			if (hyper_params->s0s1_dicts_right.find(_atomFeat.str_s0s1SW) != hyper_params->s0s1_dicts_right.end()){
				_atomFeat.sid_s0s1arcr = 1;
			}
			else{
				_atomFeat.sid_s0s1arcr = 2;
			}
		}

		_atomFeat.stacksize = _stacksize;

		lastTag = _wend == -1 ? nullkey : CTag::TAG_STRING[_tag];
		_atomFeat.sid_1WTagD = 0;
		if (hyper_params->word_tags.find(_atomFeat.str_1W) != hyper_params->word_tags.end()){
			if (hyper_params->word_tags[_atomFeat.str_1W].find(lastTag) != hyper_params->word_tags[_atomFeat.str_1W].end()){
				if (hyper_params->word_tags[_atomFeat.str_1W][lastTag] > hyper_params->maxfreq / 5000 + hyper_params->threshold){
					_atomFeat.sid_1WTagD = 1;
				}
				else{
					_atomFeat.sid_1WTagD = 2;
				}
			}
			else{
				_atomFeat.sid_1WTagD = 3;
			}	
		}

		//
		if (model_params != NULL){
			_atomFeat.convert2Id(model_params);
		}
	}
};


class CScoredState {
public:
	CStateItem *item;
	int ac;
	dtype score;
	bool bGold;

public:
	CScoredState() : item(0), score(0), ac(0), bGold(0){
	}

	CScoredState(const CScoredState& other) : item(other.item), score(other.score), ac(other.ac), bGold(other.bGold){

	}

public:
	bool operator <(const CScoredState &a1) const {
		return score < a1.score;
	}
	bool operator >(const CScoredState &a1) const {
		return score > a1.score;
	}
	bool operator <=(const CScoredState &a1) const {
		return score <= a1.score;
	}
	bool operator >=(const CScoredState &a1) const {
		return score >= a1.score;
	}
};

class CScoredState_Compare {
public:
	int operator()(const CScoredState &o1, const CScoredState &o2) const {

		if (o1.score < o2.score)
			return -1;
		else if (o1.score > o2.score)
			return 1;
		else
			return 0;
	}
};



#endif /* TAGGER_STATE_H_ */
