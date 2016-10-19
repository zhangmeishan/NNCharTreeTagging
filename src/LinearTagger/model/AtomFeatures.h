/*
 * AtomFeatures.h
 *
 *  Created on: Aug 25, 2016
 *      Author: mszhang
 */

#ifndef SRC_AtomFeatures_H_
#define SRC_AtomFeatures_H_
#include "ModelParams.h"
struct AtomFeatures {
public:
	string str_C0;
	string str_1C;  //equals str_1Wcn
	string str_2C; 

	string str_CT0;
	string str_1CT;  //equals str_1Wcn
	string str_2CT;

	string str_CC0;
	string str_1CC;  

	string str_1W;
	string str_1Wc0;
	vector<string> str_1Wci;

	string str_2W;
	string str_2Wc0;
	string str_2Wcn;

	//additional for word inner structures
	string str_s0SW;
	string str_s1SW;
	string str_s2SW;
	string str_s0s1SW;
	string str_s0SWhc;
	string str_s1SWhc;
	string str_s2SWhc;
	string str_1Whc;
	string str_2Whc;

	//integer features directly
public:
	int sid_1WD;
	int sid_1WL;
	int sid_1WTagD;
	int sid_2WL;

	//additional for pos tagging
	int sid_1WP;
	int sid_2WP;
	//int sid_0WP; //extracted from action drectly

	//additional for word inner structures
	int sid_s0s1SWL;
	int sid_s0s1arcl; 
	int sid_s0s1arcr;
	int sid_s0s1SWD;

	int sid_s0t;

public:
	int sid_C0;
	int sid_1C;  //equals str_1Wcn
	int sid_2C;

	int sid_CT0;
	int sid_1CT;  //equals str_1Wcn
	int sid_2CT;

	int sid_CC0;
	int sid_1CC;

	int sid_1W;
	int sid_1Wc0;
	vector<int> sid_1Wci;

	int sid_2W;
	int sid_2Wc0;
	int sid_2Wcn;

	int sid_s0SW;
	int sid_s1SW;
	int sid_s2SW;
	int sid_s0SWhc;
	int sid_s1SWhc;
	int sid_s2SWhc;
	int sid_1Whc;
	int sid_2Whc;

	int stacksize;

public:
	void clear(){
		str_C0 = "";
		str_1C = "";
		str_2C = "";

		str_CT0 = "";
		str_1CT = "";
		str_2CT = "";

		str_CC0 = "";
		str_1CC = "";

		str_1W = "";
		str_1Wc0 = "";
		str_1Wci.clear();

		str_2W = "";
		str_2Wc0 = "";
		str_2Wcn = "";	

		str_s0SW = "";
		str_s1SW = "";
		str_s2SW = "";
		str_s0s1SW = "";
		str_s0SWhc = "";
		str_s1SWhc = "";
		str_s2SWhc = "";
		str_1Whc = "";
		str_2Whc = "";

		sid_C0 = -1;
		sid_1C = -1;
		sid_2C = -1;

		//ids
		sid_CT0 = -1;
		sid_1CT = -1;
		sid_2CT = -1;

		sid_CC0 = -1;
		sid_1CC = -1;

		sid_1W = -1;
		sid_1WD = -1;
		sid_1WTagD = -1;
		sid_1WL = -1;
		sid_1Wc0 = -1;
		sid_1Wci.clear();

		sid_2W = -1;
		sid_2WL = -1;
		sid_2Wc0 = -1;
		sid_2Wcn = -1;

		sid_s0SW = -1;
		sid_s1SW = -1;
		sid_s2SW = -1;
		sid_s0SWhc = -1;
		sid_s1SWhc = -1;
		sid_s2SWhc = -1;
		sid_1Whc = -1;
		sid_2Whc = -1;

		sid_1WP = -1;
		sid_2WP = -1;

		sid_s0s1SWL = -1;
		sid_s0s1arcl = -1;
		sid_s0s1arcr = -1;
		sid_s0s1SWD = -1;

		sid_s0t = -1;

		stacksize = -1;
	}

public:
	void convert2Id(ModelParams* model){
		sid_C0 = model->chars.from_string(str_C0);
		sid_1C = model->chars.from_string(str_1C);
		sid_2C = model->chars.from_string(str_2C);

		sid_CT0 = model->charTypes.from_string(str_CT0);
		sid_1CT = model->charTypes.from_string(str_1CT);
		sid_2CT = model->charTypes.from_string(str_2CT);

		sid_CC0 = model->charTypes.from_string(str_CC0);
		sid_1CC = model->charTypes.from_string(str_1CC);

		sid_1W = model->words.from_string(str_1W);
		sid_1Wc0 = model->chars.from_string(str_1Wc0);
		sid_1Wci.resize(str_1Wci.size());
		for (int idx = 0; idx < str_1Wci.size(); idx++){
			sid_1Wci[idx] = model->chars.from_string(str_1Wci[idx]);
		}

		sid_2W = model->words.from_string(str_2W);
		sid_2Wc0 = model->chars.from_string(str_2Wc0);
		sid_2Wcn = model->chars.from_string(str_2Wcn);

		sid_s0SW = model->subwords.from_string(str_s0SW);
		sid_s1SW = model->subwords.from_string(str_s1SW);
		sid_s2SW = model->subwords.from_string(str_s2SW);
		sid_s0SWhc = model->chars.from_string(str_s0SWhc);
		sid_s1SWhc = model->chars.from_string(str_s1SWhc);
		sid_s2SWhc = model->chars.from_string(str_s2SWhc);
		sid_1Whc = model->chars.from_string(str_1Whc);
		sid_2Whc = model->chars.from_string(str_2Whc);
	}

public:
	void collectFeatures(const CAction& ac, ModelParams* model){
		static int sid_ac;
		sid_ac = ac.code();
		if (ac.isAppend()){
			model->app_1C_C0.collectFeature(sid_1C, sid_C0);
			model->app_1Wc0_C0.collectFeature(sid_1Wc0, sid_C0);
			model->app_2CT_1CT_CT0.collectFeature(sid_2CT, sid_1CT, sid_CT0);
		}

		if (ac.isSeparate() || ac.isFinish() || ac.isIdle()){
			model->sep_1C_C0.collectFeature(sid_1C, sid_C0);
			model->sep_1Wc0_C0.collectFeature(sid_1Wc0, sid_C0);
			model->sep_2CT_1CT_CT0.collectFeature(sid_2CT, sid_1CT, sid_CT0);
			model->sep_1W.collectFeature(sid_1W);
			if (sid_1WD == 1)model->sep_1WD_1WL.collectFeature(sid_1WD, sid_1WL);	
			if (sid_1WL == 1)model->sep_1WSingle.collectFeature(sid_1W);
			model->sep_1W_C0.collectFeature(sid_1W, sid_C0);
			model->sep_2W_1W.collectFeature(sid_2W, sid_1W);
			model->sep_2Wc0_1W.collectFeature(sid_2Wc0, sid_1W);
			model->sep_2Wcn_1W.collectFeature(sid_2Wcn, sid_1W);
			model->sep_2Wc0_1Wc0.collectFeature(sid_2Wc0, sid_1Wc0);
			model->sep_2Wcn_1Wcn.collectFeature(sid_2Wcn, sid_1C);
			model->sep_2W_1WL.collectFeature(sid_2W, sid_1WL);
			model->sep_2WL_1W.collectFeature(sid_2WL, sid_1W);
			model->sep_2W_1Wcn.collectFeature(sid_2W, sid_1C);
			model->sep_1Wc0_1WL.collectFeature(sid_1Wc0, sid_1WL);
			model->sep_1Wcn_1WL.collectFeature(sid_1C, sid_1WL);
			for (int idx = 0; idx < sid_1Wci.size(); idx++){
				model->sep_1Wci_1Wcn_1WP.collectFeature(sid_1Wci[idx], sid_1C, sid_1WP);
			}
		}

		if (stacksize > 1){
			model->arc_s0w_ac.collectFeature(sid_s0SW);
			model->arc_s0t_ac.collectFeature(sid_s0t);
			model->arc_s0w_s0t_ac.collectFeature(sid_s0SW, sid_s0t);
			model->arc_s1w_ac.collectFeature(sid_s1SW);
			model->arc_s1w_s1t_ac.collectFeature(sid_s1SW, sid_s0t);
			model->arc_n0c_ac.collectFeature(sid_C0);
			model->arc_s0w_s1w_ac.collectFeature(sid_s0SW, sid_s1SW);
			model->arc_s0w_s1w_s0t_ac.collectFeature(sid_s0SW, sid_s1SW, sid_s0t);
			model->arc_s0w_n0c_ac.collectFeature(sid_s0SW, sid_C0);
			model->arc_s0w_n0c_s0t_ac.collectFeature(sid_s0SW, sid_C0, sid_s0t);
			model->arc_s1w_n0c_ac.collectFeature(sid_s1SW, sid_C0);
			model->arc_s1w_n0c_s0t_ac.collectFeature(sid_s1SW, sid_C0, sid_s0t);
			model->arc_n0c_s0t_ac.collectFeature(sid_C0, sid_s0t);
			model->arc_n0c_s0w_s1w_ac.collectFeature(sid_C0, sid_s0SW, sid_s1SW);
			model->arc_s0w_s1w_s2w_ac.collectFeature(sid_s0SW, sid_s1SW, sid_s2SW);
			model->arc_s0c_ac.collectFeature(sid_s0SWhc);
			model->arc_s0c_s0t_ac.collectFeature(sid_s0SWhc, sid_s0t);
			model->arc_s1c_ac.collectFeature(sid_s1SWhc);
			model->arc_s1c_s0t_ac.collectFeature(sid_s1SWhc, sid_s0t);
			model->arc_s0c_s1c_ac.collectFeature(sid_s0SWhc, sid_s1SWhc);
			model->arc_s0c_s1c_s0t_ac.collectFeature(sid_s0SWhc, sid_s1SWhc, sid_s0t);
			model->arc_s0c_n0c_ac.collectFeature(sid_s0SWhc, sid_C0);
			model->arc_s0c_n0c_s0t_ac.collectFeature(sid_s0SWhc, sid_C0, sid_s0t);
			model->arc_s1c_n0c_ac.collectFeature(sid_s1SWhc, sid_C0);
			model->arc_s1c_n0c_s0t_ac.collectFeature(sid_s1SWhc, sid_C0, sid_s0t);
			model->arc_n0c_s0c_s1c_ac.collectFeature(sid_C0, sid_s0SWhc, sid_s1SWhc);
			model->arc_s0c_s1c_s2c_ac.collectFeature(sid_s0SWhc, sid_s1SWhc, sid_s2SWhc);

			if (sid_s0s1arcl == 1)model->arc_s0s1left_s0s1SWL_ac.collectFeature(sid_s0s1arcl, sid_s0s1SWL);
			if (sid_s0s1arcr == 1)model->arc_s0s1right_s0s1SWL_ac.collectFeature(sid_s0s1arcr, sid_s0s1SWL);
			if (sid_s0s1SWD == 1)model->arc_s0s1SWD_s0s1SWL_ac.collectFeature(sid_s0s1SWD, sid_s0s1SWL);
		}

		if (ac.isSeparate() || ac.isFinish() || ac.isIdle()){
			model->pos_1W_1WP.collectFeature(sid_1W, sid_1WP);
			model->pos_1W_2WP.collectFeature(sid_1W, sid_2WP);
			model->pos_2Wcn_1W_1WP.collectFeature(sid_2Wcn, sid_1W, sid_1WP);
			model->pos_2Wcn_1W_n0c_1WP.collectFeature(sid_2Wcn, sid_1W, sid_C0, sid_1WP);
			model->pos_1Wcn_1WP.collectFeature(sid_1C, sid_1WP);
			model->pos_1CC_1WP.collectFeature(sid_1CC, sid_1WP);
			model->pos_1WP_ac.collectFeature(sid_1WP);
			model->pos_1WL_1WP_ac.collectFeature(sid_1WL, sid_1WP);
			model->pos_1WL_1WP_2WP.collectFeature(sid_1WL, sid_1WP, sid_2WP);
			model->pos_1WL_1WP_2WP_ac.collectFeature(sid_1WL, sid_1WP, sid_2WP);
			model->pos_1W_ac.collectFeature(sid_1W);
			model->pos_1WP_2WP_ac.collectFeature(sid_1WP, sid_2WP);
			model->pos_1W_n0c_1WP.collectFeature(sid_1W, sid_C0, sid_1WP);
			model->pos_n0c_ac.collectFeature(sid_C0);
			model->pos_CC0_ac.collectFeature(sid_CC0);
			model->pos_n0c_1WP_ac.collectFeature(sid_C0, sid_1WP);
			model->pos_n0c_1WP_2WP_ac.collectFeature(sid_C0, sid_1WP, sid_2WP);
			model->pos_n0c_1WP.collectFeature(sid_C0, sid_1WP);
			model->pos_n0c_1Wcn_1WP_ac.collectFeature(sid_C0, sid_1C, sid_1WP);
			model->pos_1W_2WP_ac.collectFeature(sid_1W, sid_2WP);
			model->pos_2W_1WP_ac.collectFeature(sid_2W, sid_1WP);
			model->sep_1Whc_C0.collectFeature(sid_1Whc, sid_C0);
			model->sep_2Whc_1Whc.collectFeature(sid_2Whc, sid_1Whc);
			model->sep_2Wc0_1Whc.collectFeature(sid_2Wc0, sid_1Whc);
			model->sep_2Wcn_1Whc.collectFeature(sid_2Wcn, sid_1Whc);
			model->sep_2W_1Whc.collectFeature(sid_2W, sid_1Whc);
			model->sep_2Whc_1W.collectFeature(sid_2Whc, sid_1W);
			model->sep_2Wc_1WL.collectFeature(sid_2Whc, sid_1WL);
			model->sep_2WL_1Wc.collectFeature(sid_2WL, sid_1Whc);
			model->sep_2Whc_1Wcn.collectFeature(sid_2Whc, sid_1C);
			model->sep_1Whc_1WL.collectFeature(sid_1Whc, sid_1WL);
			model->pos_1Whc_1WP.collectFeature(sid_1Whc, sid_1WP);
			model->pos_1Whc_2WP.collectFeature(sid_1Whc, sid_2WP);
			model->pos_2Wcn_1Whc_1WP.collectFeature(sid_2Wcn, sid_1Whc, sid_1WP);
			model->pos_2Wcn_1Whc_n0c_1WP.collectFeature(sid_2Wcn, sid_1Whc, sid_C0, sid_1WP);
			model->pos_1Whc_ac.collectFeature(sid_1Whc);
			model->pos_1Whc_n0c_1WP.collectFeature(sid_1Whc, sid_C0, sid_1WP);
			model->pos_1Whc_2WP_ac.collectFeature(sid_1Whc, sid_2WP);
			model->pos_2Whc_1WP_ac.collectFeature(sid_2Whc, sid_1WP);
		}

		if (ac.isAppend()){
			model->app_1C_C0_1WP.collectFeature(sid_1C, sid_C0, sid_1WP);
			model->app_1Wc0_C0_1WP.collectFeature(sid_1Wc0, sid_C0, sid_1WP);
			model->app_2CT_1CT_CT0_1WP.collectFeature(sid_2CT, sid_1CT, sid_CT0, sid_1WP);
		}


		if (ac.isSeparate() || ac.isFinish() || ac.isIdle()){
			if (sid_1WTagD == 1)model->sep_1WTagD_1WP_1WL.collectFeature(sid_1WTagD, sid_1WP, sid_1WL);
		}

	}

};

#endif /* SRC_AtomFeatures_H_ */
