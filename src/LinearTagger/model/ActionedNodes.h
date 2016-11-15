/*
 * Feature.h
 *
 *  Created on: Aug 25, 2016
 *      Author: mszhang
 */

#ifndef SRC_ActionedNodes_H_
#define SRC_ActionedNodes_H_

#include "ModelParams.h"
#include "AtomFeatures.h"

struct ActionedNodes {
	const static int max_seg_length = 5;
	//append feature parameters
	SparseC2Node  app_1C_C0;
	SparseC2Node  app_1Wc0_C0;
	SparseC3Node  app_2CT_1CT_CT0;

	//separate feature parameters
	SparseC2Node  sep_1C_C0;
	SparseC2Node  sep_1Wc0_C0;
	SparseC3Node  sep_2CT_1CT_CT0;
	SparseC1Node  sep_1W;
	SparseC2Node  sep_1WD_1WL;
	SparseC1Node  sep_1WSingle;
	SparseC2Node  sep_1W_C0;
	SparseC2Node  sep_2W_1W;
	SparseC2Node  sep_2Wc0_1W;
	SparseC2Node  sep_2Wcn_1W;
	SparseC2Node  sep_2Wc0_1Wc0;
	SparseC2Node  sep_2Wcn_1Wcn;
	SparseC2Node  sep_2W_1WL;
	SparseC2Node  sep_2WL_1W;
	SparseC2Node  sep_2W_1Wcn;
	SparseC2Node  sep_1Wc0_1WL;
	SparseC2Node  sep_1Wcn_1WL;

	vector<SparseC3Node>  sep_1Wci_1Wcn_1WP;

	//new features
	SparseC1Node arc_s0w_ac;
	SparseC1Node arc_s0t_ac;
	SparseC2Node arc_s0w_s0t_ac;

	SparseC1Node arc_s1w_ac;
	SparseC2Node arc_s1w_s1t_ac;

	SparseC1Node arc_n0c_ac;

	SparseC2Node arc_s0w_s1w_ac;
	SparseC3Node arc_s0w_s1w_s0t_ac;

	SparseC2Node arc_s0w_n0c_ac;
	SparseC3Node arc_s0w_n0c_s0t_ac;

	SparseC2Node arc_s1w_n0c_ac;
	SparseC3Node arc_s1w_n0c_s0t_ac;

	SparseC2Node arc_n0c_s0t_ac;

	SparseC3Node arc_n0c_s0w_s1w_ac;
	SparseC3Node arc_s0w_s1w_s2w_ac;

	SparseC1Node arc_s0c_ac;
	SparseC2Node arc_s0c_s0t_ac;

	SparseC1Node arc_s1c_ac;
	SparseC2Node arc_s1c_s0t_ac;

	SparseC2Node arc_s0c_s1c_ac;
	SparseC3Node arc_s0c_s1c_s0t_ac;

	SparseC2Node arc_s0c_n0c_ac;
	SparseC3Node arc_s0c_n0c_s0t_ac;

	SparseC2Node arc_s1c_n0c_ac;
	SparseC3Node arc_s1c_n0c_s0t_ac;

	SparseC3Node arc_n0c_s0c_s1c_ac;
	SparseC3Node arc_s0c_s1c_s2c_ac;

	SparseC2Node pos_1W_1WP;
	SparseC2Node pos_1W_2WP;
	SparseC3Node pos_2Wcn_1W_1WP;
	SparseC4Node pos_2Wcn_1W_n0c_1WP;
	SparseC2Node pos_1Wcn_1WP;
	SparseC2Node pos_1CC_1WP;

	SparseC1Node pos_1WP_ac;
	SparseC2Node pos_1WL_1WP_ac;
	SparseC3Node pos_1WL_1WP_2WP;
	SparseC3Node pos_1WL_1WP_2WP_ac;

	SparseC1Node pos_1W_ac;
	SparseC2Node pos_1WP_2WP_ac;
	SparseC3Node pos_1W_n0c_1WP;

	SparseC1Node pos_n0c_ac;
	SparseC1Node pos_CC0_ac;

	SparseC2Node pos_n0c_1WP_ac;
	SparseC3Node pos_n0c_1WP_2WP_ac;

	SparseC2Node pos_n0c_1WP;

	SparseC3Node pos_n0c_1Wcn_1WP_ac;

	SparseC2Node pos_1W_2WP_ac;
	SparseC2Node pos_2W_1WP_ac;

	SparseC3Node  app_1C_C0_1WP;
	SparseC3Node  app_1Wc0_C0_1WP;
	SparseC4Node  app_2CT_1CT_CT0_1WP;



	SparseC2Node  sep_1Whc_C0;
	SparseC2Node  sep_2Whc_1Whc;
	SparseC2Node  sep_2Wc0_1Whc;
	SparseC2Node  sep_2Wcn_1Whc;
	SparseC2Node  sep_2W_1Whc;
	SparseC2Node  sep_2Whc_1W;
	SparseC2Node  sep_2Wc_1WL;
	SparseC2Node  sep_2WL_1Wc;
	SparseC2Node  sep_2Whc_1Wcn;
	SparseC2Node  sep_1Whc_1WL;


	SparseC2Node pos_1Whc_1WP;
	SparseC2Node pos_1Whc_2WP;
	SparseC3Node pos_2Wcn_1Whc_1WP;
	SparseC4Node pos_2Wcn_1Whc_n0c_1WP;

	SparseC1Node pos_1Whc_ac;
	SparseC3Node pos_1Whc_n0c_1WP;

	SparseC2Node pos_1Whc_2WP_ac;
	SparseC2Node pos_2Whc_1WP_ac;


	SparseC2Node arc_s0s1left_s0s1SWL_ac;
	SparseC2Node arc_s0s1right_s0s1SWL_ac;
	SparseC2Node arc_s0s1SWD_s0s1SWL_ac;

	//SparseC3Node sep_1WTagD_1WP_1WL;

	vector<SPAddNode> outputs;

public:
	inline void initial(ModelParams& params, HyperParams& hyparams, AlignedMemoryPool* mem){
		app_1C_C0.setParam(&params.app_1C_C0);
		app_1Wc0_C0.setParam(&params.app_1Wc0_C0);
		app_2CT_1CT_CT0.setParam(&params.app_2CT_1CT_CT0);

		sep_1C_C0.setParam(&params.sep_1C_C0);
		sep_1Wc0_C0.setParam(&params.sep_1Wc0_C0);
		sep_2CT_1CT_CT0.setParam(&params.sep_2CT_1CT_CT0);
		sep_1W.setParam(&params.sep_1W);
		sep_1WD_1WL.setParam(&params.sep_1WD_1WL);
		sep_1WSingle.setParam(&params.sep_1WSingle);
		sep_1W_C0.setParam(&params.sep_1W_C0);
		sep_2W_1W.setParam(&params.sep_2W_1W);
		sep_2Wc0_1W.setParam(&params.sep_2Wc0_1W);
		sep_2Wcn_1W.setParam(&params.sep_2Wcn_1W);
		sep_2Wc0_1Wc0.setParam(&params.sep_2Wc0_1Wc0);
		sep_2Wcn_1Wcn.setParam(&params.sep_2Wcn_1Wcn);
		sep_2W_1WL.setParam(&params.sep_2W_1WL);
		sep_2WL_1W.setParam(&params.sep_2WL_1W);
		sep_2W_1Wcn.setParam(&params.sep_2W_1Wcn);
		sep_1Wc0_1WL.setParam(&params.sep_1Wc0_1WL);
		sep_1Wcn_1WL.setParam(&params.sep_1Wcn_1WL);
		sep_1Wci_1Wcn_1WP.resize(max_seg_length);
		for (int idx = 0; idx < max_seg_length; idx++){
			sep_1Wci_1Wcn_1WP[idx].setParam(&params.sep_1Wci_1Wcn_1WP);
		}

		arc_s0w_ac.setParam(&params.arc_s0w_ac);
		arc_s0t_ac.setParam(&params.arc_s0t_ac);
		arc_s0w_s0t_ac.setParam(&params.arc_s0w_s0t_ac);
		arc_s1w_ac.setParam(&params.arc_s1w_ac);
		arc_s1w_s1t_ac.setParam(&params.arc_s1w_s1t_ac);
		arc_n0c_ac.setParam(&params.arc_n0c_ac);
		arc_s0w_s1w_ac.setParam(&params.arc_s0w_s1w_ac);
		arc_s0w_s1w_s0t_ac.setParam(&params.arc_s0w_s1w_s0t_ac);
		arc_s0w_n0c_ac.setParam(&params.arc_s0w_n0c_ac);
		arc_s0w_n0c_s0t_ac.setParam(&params.arc_s0w_n0c_s0t_ac);
		arc_s1w_n0c_ac.setParam(&params.arc_s1w_n0c_ac);
		arc_s1w_n0c_s0t_ac.setParam(&params.arc_s1w_n0c_s0t_ac);
		arc_n0c_s0t_ac.setParam(&params.arc_n0c_s0t_ac);
		arc_n0c_s0w_s1w_ac.setParam(&params.arc_n0c_s0w_s1w_ac);
		arc_s0w_s1w_s2w_ac.setParam(&params.arc_s0w_s1w_s2w_ac);
		arc_s0c_ac.setParam(&params.arc_s0c_ac);
		arc_s0c_s0t_ac.setParam(&params.arc_s0c_s0t_ac);
		arc_s1c_ac.setParam(&params.arc_s1c_ac);
		arc_s1c_s0t_ac.setParam(&params.arc_s1c_s0t_ac);
		arc_s0c_s1c_ac.setParam(&params.arc_s0c_s1c_ac);
		arc_s0c_s1c_s0t_ac.setParam(&params.arc_s0c_s1c_s0t_ac);
		arc_s0c_n0c_ac.setParam(&params.arc_s0c_n0c_ac);
		arc_s0c_n0c_s0t_ac.setParam(&params.arc_s0c_n0c_s0t_ac);
		arc_s1c_n0c_ac.setParam(&params.arc_s1c_n0c_ac);
		arc_s1c_n0c_s0t_ac.setParam(&params.arc_s1c_n0c_s0t_ac);
		arc_n0c_s0c_s1c_ac.setParam(&params.arc_n0c_s0c_s1c_ac);
		arc_s0c_s1c_s2c_ac.setParam(&params.arc_s0c_s1c_s2c_ac);
		pos_1W_1WP.setParam(&params.pos_1W_1WP);
		pos_1W_2WP.setParam(&params.pos_1W_2WP);
		pos_2Wcn_1W_1WP.setParam(&params.pos_2Wcn_1W_1WP);
		pos_2Wcn_1W_n0c_1WP.setParam(&params.pos_2Wcn_1W_n0c_1WP);
		pos_1Wcn_1WP.setParam(&params.pos_1Wcn_1WP);
		pos_1CC_1WP.setParam(&params.pos_1CC_1WP);
		pos_1WP_ac.setParam(&params.pos_1WP_ac);
		pos_1WL_1WP_ac.setParam(&params.pos_1WL_1WP_ac);
		pos_1WL_1WP_2WP.setParam(&params.pos_1WL_1WP_2WP);
		pos_1WL_1WP_2WP_ac.setParam(&params.pos_1WL_1WP_2WP_ac);
		pos_1W_ac.setParam(&params.pos_1W_ac);
		pos_1WP_2WP_ac.setParam(&params.pos_1WP_2WP_ac);
		pos_1W_n0c_1WP.setParam(&params.pos_1W_n0c_1WP);
		pos_n0c_ac.setParam(&params.pos_n0c_ac);
		pos_CC0_ac.setParam(&params.pos_CC0_ac);
		pos_n0c_1WP_ac.setParam(&params.pos_n0c_1WP_ac);
		pos_n0c_1WP_2WP_ac.setParam(&params.pos_n0c_1WP_2WP_ac);
		pos_n0c_1WP.setParam(&params.pos_n0c_1WP);
		pos_n0c_1Wcn_1WP_ac.setParam(&params.pos_n0c_1Wcn_1WP_ac);
		pos_1W_2WP_ac.setParam(&params.pos_1W_2WP_ac);
		pos_2W_1WP_ac.setParam(&params.pos_2W_1WP_ac);
		app_1C_C0_1WP.setParam(&params.app_1C_C0_1WP);
		app_1Wc0_C0_1WP.setParam(&params.app_1Wc0_C0_1WP);
		app_2CT_1CT_CT0_1WP.setParam(&params.app_2CT_1CT_CT0_1WP);
		sep_1Whc_C0.setParam(&params.sep_1Whc_C0);
		sep_2Whc_1Whc.setParam(&params.sep_2Whc_1Whc);
		sep_2Wc0_1Whc.setParam(&params.sep_2Wc0_1Whc);
		sep_2Wcn_1Whc.setParam(&params.sep_2Wcn_1Whc);
		sep_2W_1Whc.setParam(&params.sep_2W_1Whc);
		sep_2Whc_1W.setParam(&params.sep_2Whc_1W);
		sep_2Wc_1WL.setParam(&params.sep_2Wc_1WL);
		sep_2WL_1Wc.setParam(&params.sep_2WL_1Wc);
		sep_2Whc_1Wcn.setParam(&params.sep_2Whc_1Wcn);
		sep_1Whc_1WL.setParam(&params.sep_1Whc_1WL);
		pos_1Whc_1WP.setParam(&params.pos_1Whc_1WP);
		pos_1Whc_2WP.setParam(&params.pos_1Whc_2WP);
		pos_2Wcn_1Whc_1WP.setParam(&params.pos_2Wcn_1Whc_1WP);
		pos_2Wcn_1Whc_n0c_1WP.setParam(&params.pos_2Wcn_1Whc_n0c_1WP);
		pos_1Whc_ac.setParam(&params.pos_1Whc_ac);
		pos_1Whc_n0c_1WP.setParam(&params.pos_1Whc_n0c_1WP);
		pos_1Whc_2WP_ac.setParam(&params.pos_1Whc_2WP_ac);
		pos_2Whc_1WP_ac.setParam(&params.pos_2Whc_1WP_ac);


		arc_s0s1left_s0s1SWL_ac.setParam(&params.arc_s0s1left_s0s1SWL_ac);
		arc_s0s1right_s0s1SWL_ac.setParam(&params.arc_s0s1right_s0s1SWL_ac);
		arc_s0s1SWD_s0s1SWL_ac.setParam(&params.arc_s0s1SWD_s0s1SWL_ac);

		//sep_1WTagD_1WP_1WL.setParam(&params.sep_1WTagD_1WP_1WL);

		outputs.resize(hyparams.action_num);
		
		app_1C_C0.init(1, -1, mem);
		app_1Wc0_C0.init(1, -1, mem);
		app_2CT_1CT_CT0.init(1, -1, mem);

		sep_1C_C0.init(1, -1, mem);
		sep_1Wc0_C0.init(1, -1, mem);
		sep_2CT_1CT_CT0.init(1, -1, mem);
		sep_1W.init(1, -1, mem);
		sep_1WD_1WL.init(1, -1, mem);
		sep_1WSingle.init(1, -1, mem);
		sep_1W_C0.init(1, -1, mem);
		sep_2W_1W.init(1, -1, mem);
		sep_2Wc0_1W.init(1, -1, mem);
		sep_2Wcn_1W.init(1, -1, mem);
		sep_2Wc0_1Wc0.init(1, -1, mem);
		sep_2Wcn_1Wcn.init(1, -1, mem);
		sep_2W_1WL.init(1, -1, mem);
		sep_2WL_1W.init(1, -1, mem);
		sep_2W_1Wcn.init(1, -1, mem);
		sep_1Wc0_1WL.init(1, -1, mem);
		sep_1Wcn_1WL.init(1, -1, mem);
		for (int idx = 0; idx < max_seg_length; idx++){
			sep_1Wci_1Wcn_1WP[idx].init(1, -1, mem);
		}

		arc_s0w_ac.init(hyparams.action_num, -1, mem);
		arc_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_s0w_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_s1w_ac.init(hyparams.action_num, -1, mem);
		arc_s1w_s1t_ac.init(hyparams.action_num, -1, mem);
		arc_n0c_ac.init(hyparams.action_num, -1, mem);
		arc_s0w_s1w_ac.init(hyparams.action_num, -1, mem);
		arc_s0w_s1w_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_s0w_n0c_ac.init(hyparams.action_num, -1, mem);
		arc_s0w_n0c_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_s1w_n0c_ac.init(hyparams.action_num, -1, mem);
		arc_s1w_n0c_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_n0c_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_n0c_s0w_s1w_ac.init(hyparams.action_num, -1, mem);
		arc_s0w_s1w_s2w_ac.init(hyparams.action_num, -1, mem);
		arc_s0c_ac.init(hyparams.action_num, -1, mem);
		arc_s0c_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_s1c_ac.init(hyparams.action_num, -1, mem);
		arc_s1c_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_s0c_s1c_ac.init(hyparams.action_num, -1, mem);
		arc_s0c_s1c_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_s0c_n0c_ac.init(hyparams.action_num, -1, mem);
		arc_s0c_n0c_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_s1c_n0c_ac.init(hyparams.action_num, -1, mem);
		arc_s1c_n0c_s0t_ac.init(hyparams.action_num, -1, mem);
		arc_n0c_s0c_s1c_ac.init(hyparams.action_num, -1, mem);
		arc_s0c_s1c_s2c_ac.init(hyparams.action_num, -1, mem);
		pos_1W_1WP.init(1, -1, mem);
		pos_1W_2WP.init(1, -1, mem);
		pos_2Wcn_1W_1WP.init(1, -1, mem);
		pos_2Wcn_1W_n0c_1WP.init(1, -1, mem);
		pos_1Wcn_1WP.init(1, -1, mem);
		pos_1CC_1WP.init(1, -1, mem);
		pos_1WP_ac.init(hyparams.action_num, -1, mem);
		pos_1WL_1WP_ac.init(hyparams.action_num, -1, mem);
		pos_1WL_1WP_2WP.init(1, -1, mem);
		pos_1WL_1WP_2WP_ac.init(hyparams.action_num, -1, mem);
		pos_1W_ac.init(hyparams.action_num, -1, mem);
		pos_1WP_2WP_ac.init(hyparams.action_num, -1, mem);
		pos_1W_n0c_1WP.init(1, -1, mem);
		pos_n0c_ac.init(hyparams.action_num, -1, mem);
		pos_CC0_ac.init(hyparams.action_num, -1, mem);
		pos_n0c_1WP_ac.init(hyparams.action_num, -1, mem);
		pos_n0c_1WP_2WP_ac.init(hyparams.action_num, -1, mem);
		pos_n0c_1WP.init(1, -1, mem);
		pos_n0c_1Wcn_1WP_ac.init(hyparams.action_num, -1, mem);
		pos_1W_2WP_ac.init(hyparams.action_num, -1, mem);
		pos_2W_1WP_ac.init(hyparams.action_num, -1, mem);
		app_1C_C0_1WP.init(1, -1, mem);
		app_1Wc0_C0_1WP.init(1, -1, mem);
		app_2CT_1CT_CT0_1WP.init(1, -1, mem);
		sep_1Whc_C0.init(1, -1, mem);
		sep_2Whc_1Whc.init(1, -1, mem);
		sep_2Wc0_1Whc.init(1, -1, mem);
		sep_2Wcn_1Whc.init(1, -1, mem);
		sep_2W_1Whc.init(1, -1, mem);
		sep_2Whc_1W.init(1, -1, mem);
		sep_2Wc_1WL.init(1, -1, mem);
		sep_2WL_1Wc.init(1, -1, mem);
		sep_2Whc_1Wcn.init(1, -1, mem);
		sep_1Whc_1WL.init(1, -1, mem);
		pos_1Whc_1WP.init(1, -1, mem);
		pos_1Whc_2WP.init(1, -1, mem);
		pos_2Wcn_1Whc_1WP.init(1, -1, mem);
		pos_2Wcn_1Whc_n0c_1WP.init(1, -1, mem);
		pos_1Whc_ac.init(hyparams.action_num, -1, mem);
		pos_1Whc_n0c_1WP.init(1, -1, mem);
		pos_1Whc_2WP_ac.init(hyparams.action_num, -1, mem);
		pos_2Whc_1WP_ac.init(hyparams.action_num, -1, mem);

		arc_s0s1left_s0s1SWL_ac.init(hyparams.action_num, -1, mem);
		arc_s0s1right_s0s1SWL_ac.init(hyparams.action_num, -1, mem);
		arc_s0s1SWD_s0s1SWL_ac.init(hyparams.action_num, -1, mem);

		//sep_1WTagD_1WP_1WL.init(1, -1, mem);	
		
		for (int idx = 0; idx < hyparams.action_num; idx++) {
			outputs[idx].init(1, -1, mem);
		}		
	}


public:
	inline void forward(Graph* cg, const vector<CAction>& actions, const AtomFeatures& atomFeat, PNode prevStateNode){
		app_1C_C0.forward(cg, atomFeat.sid_1C, atomFeat.sid_C0);
		app_1Wc0_C0.forward(cg, atomFeat.sid_1Wc0, atomFeat.sid_C0);
		app_2CT_1CT_CT0.forward(cg, atomFeat.sid_2CT, atomFeat.sid_1CT, atomFeat.sid_CT0);

		sep_1C_C0.forward(cg, atomFeat.sid_1C, atomFeat.sid_C0);
		sep_1Wc0_C0.forward(cg, atomFeat.sid_1Wc0, atomFeat.sid_C0);
		sep_2CT_1CT_CT0.forward(cg, atomFeat.sid_2CT, atomFeat.sid_1CT, atomFeat.sid_CT0);
		sep_1W.forward(cg, atomFeat.sid_1W);
		if (atomFeat.sid_1WD == 1)sep_1WD_1WL.forward(cg, atomFeat.sid_1WD, atomFeat.sid_1WL);
		if (atomFeat.sid_1WL == 1)sep_1WSingle.forward(cg, atomFeat.sid_1W);
		sep_1W_C0.forward(cg, atomFeat.sid_1W, atomFeat.sid_C0);
		sep_2W_1W.forward(cg, atomFeat.sid_2W, atomFeat.sid_1W);
		sep_2Wc0_1W.forward(cg, atomFeat.sid_2Wc0, atomFeat.sid_1W);
		sep_2Wcn_1W.forward(cg, atomFeat.sid_2Wcn, atomFeat.sid_1W);
		sep_2Wc0_1Wc0.forward(cg, atomFeat.sid_2Wc0, atomFeat.sid_1Wc0);
		sep_2Wcn_1Wcn.forward(cg, atomFeat.sid_2Wcn, atomFeat.sid_1C);
		sep_2W_1WL.forward(cg, atomFeat.sid_2W, atomFeat.sid_1WL);				
		sep_2WL_1W.forward(cg, atomFeat.sid_2WL, atomFeat.sid_1W);
		sep_2W_1Wcn.forward(cg, atomFeat.sid_2W, atomFeat.sid_1C);
		sep_1Wc0_1WL.forward(cg, atomFeat.sid_1Wc0, atomFeat.sid_1WL);
		sep_1Wcn_1WL.forward(cg, atomFeat.sid_1C, atomFeat.sid_1WL);

		for (int idy = 0; idy < atomFeat.sid_1Wci.size() && idy < max_seg_length; idy++){
			sep_1Wci_1Wcn_1WP[idy].forward(cg, atomFeat.sid_1Wci[idy], atomFeat.sid_1C, atomFeat.sid_1WP);
		}

		if (atomFeat.stacksize > 1){
			arc_s0w_ac.forward(cg, atomFeat.sid_s0SW);
			arc_s0t_ac.forward(cg, atomFeat.sid_s0t);
			arc_s0w_s0t_ac.forward(cg, atomFeat.sid_s0SW, atomFeat.sid_s0t);
			arc_s1w_ac.forward(cg, atomFeat.sid_s1SW);
			arc_s1w_s1t_ac.forward(cg, atomFeat.sid_s1SW, atomFeat.sid_s0t);
			arc_n0c_ac.forward(cg, atomFeat.sid_C0);
			arc_s0w_s1w_ac.forward(cg, atomFeat.sid_s0SW, atomFeat.sid_s1SW);
			arc_s0w_s1w_s0t_ac.forward(cg, atomFeat.sid_s0SW, atomFeat.sid_s1SW, atomFeat.sid_s0t);
			arc_s0w_n0c_ac.forward(cg, atomFeat.sid_s0SW, atomFeat.sid_C0);
			arc_s0w_n0c_s0t_ac.forward(cg, atomFeat.sid_s0SW, atomFeat.sid_C0, atomFeat.sid_s0t);
			arc_s1w_n0c_ac.forward(cg, atomFeat.sid_s1SW, atomFeat.sid_C0);
			arc_s1w_n0c_s0t_ac.forward(cg, atomFeat.sid_s1SW, atomFeat.sid_C0, atomFeat.sid_s0t);
			arc_n0c_s0t_ac.forward(cg, atomFeat.sid_C0, atomFeat.sid_s0t);
			arc_n0c_s0w_s1w_ac.forward(cg, atomFeat.sid_C0, atomFeat.sid_s0SW, atomFeat.sid_s1SW);
			arc_s0w_s1w_s2w_ac.forward(cg, atomFeat.sid_s0SW, atomFeat.sid_s1SW, atomFeat.sid_s2SW);
			arc_s0c_ac.forward(cg, atomFeat.sid_s0SWhc);
			arc_s0c_s0t_ac.forward(cg, atomFeat.sid_s0SWhc, atomFeat.sid_s0t);
			arc_s1c_ac.forward(cg, atomFeat.sid_s1SWhc);
			arc_s1c_s0t_ac.forward(cg, atomFeat.sid_s1SWhc, atomFeat.sid_s0t);
			arc_s0c_s1c_ac.forward(cg, atomFeat.sid_s0SWhc, atomFeat.sid_s1SWhc);
			arc_s0c_s1c_s0t_ac.forward(cg, atomFeat.sid_s0SWhc, atomFeat.sid_s1SWhc, atomFeat.sid_s0t);
			arc_s0c_n0c_ac.forward(cg, atomFeat.sid_s0SWhc, atomFeat.sid_C0);
			arc_s0c_n0c_s0t_ac.forward(cg, atomFeat.sid_s0SWhc, atomFeat.sid_C0, atomFeat.sid_s0t);
			arc_s1c_n0c_ac.forward(cg, atomFeat.sid_s1SWhc, atomFeat.sid_C0);
			arc_s1c_n0c_s0t_ac.forward(cg, atomFeat.sid_s1SWhc, atomFeat.sid_C0, atomFeat.sid_s0t);
			arc_n0c_s0c_s1c_ac.forward(cg, atomFeat.sid_C0, atomFeat.sid_s0SWhc, atomFeat.sid_s1SWhc);
			arc_s0c_s1c_s2c_ac.forward(cg, atomFeat.sid_s0SWhc, atomFeat.sid_s1SWhc, atomFeat.sid_s2SWhc);

			if (atomFeat.sid_s0s1arcl == 1)arc_s0s1left_s0s1SWL_ac.forward(cg, atomFeat.sid_s0s1arcl, atomFeat.sid_s0s1SWL);
			if (atomFeat.sid_s0s1arcr == 1)arc_s0s1right_s0s1SWL_ac.forward(cg, atomFeat.sid_s0s1arcr, atomFeat.sid_s0s1SWL);
			if (atomFeat.sid_s0s1SWD == 1)arc_s0s1SWD_s0s1SWL_ac.forward(cg, atomFeat.sid_s0s1SWD, atomFeat.sid_s0s1SWL);
		}

		pos_1W_1WP.forward(cg, atomFeat.sid_1W, atomFeat.sid_1WP);
		pos_1W_2WP.forward(cg, atomFeat.sid_1W, atomFeat.sid_2WP);
		pos_2Wcn_1W_1WP.forward(cg, atomFeat.sid_2Wcn, atomFeat.sid_1W, atomFeat.sid_1WP);
		pos_2Wcn_1W_n0c_1WP.forward(cg, atomFeat.sid_2Wcn, atomFeat.sid_1W, atomFeat.sid_C0, atomFeat.sid_1WP);
		pos_1Wcn_1WP.forward(cg, atomFeat.sid_1C, atomFeat.sid_1WP);
		pos_1CC_1WP.forward(cg, atomFeat.sid_1CC, atomFeat.sid_1WP);
		pos_1WP_ac.forward(cg, atomFeat.sid_1WP);
		pos_1WL_1WP_ac.forward(cg, atomFeat.sid_1WL, atomFeat.sid_1WP);
		pos_1WL_1WP_2WP.forward(cg, atomFeat.sid_1WL, atomFeat.sid_1WP, atomFeat.sid_2WP);
		pos_1WL_1WP_2WP_ac.forward(cg, atomFeat.sid_1WL, atomFeat.sid_1WP, atomFeat.sid_2WP);
		pos_1W_ac.forward(cg, atomFeat.sid_1W);
		pos_1WP_2WP_ac.forward(cg, atomFeat.sid_1WP, atomFeat.sid_2WP);
		pos_1W_n0c_1WP.forward(cg, atomFeat.sid_1W, atomFeat.sid_C0, atomFeat.sid_1WP);
		pos_n0c_ac.forward(cg, atomFeat.sid_C0);
		pos_CC0_ac.forward(cg, atomFeat.sid_CC0);
		pos_n0c_1WP_ac.forward(cg, atomFeat.sid_C0, atomFeat.sid_1WP);
		pos_n0c_1WP_2WP_ac.forward(cg, atomFeat.sid_C0, atomFeat.sid_1WP, atomFeat.sid_2WP);
		pos_n0c_1WP.forward(cg, atomFeat.sid_C0, atomFeat.sid_1WP);
		pos_n0c_1Wcn_1WP_ac.forward(cg, atomFeat.sid_C0, atomFeat.sid_1C, atomFeat.sid_1WP);
		pos_1W_2WP_ac.forward(cg, atomFeat.sid_1W, atomFeat.sid_2WP);
		pos_2W_1WP_ac.forward(cg, atomFeat.sid_2W, atomFeat.sid_1WP);
		sep_1Whc_C0.forward(cg, atomFeat.sid_1Whc, atomFeat.sid_C0);
		sep_2Whc_1Whc.forward(cg, atomFeat.sid_2Whc, atomFeat.sid_1Whc);
		sep_2Wc0_1Whc.forward(cg, atomFeat.sid_2Wc0, atomFeat.sid_1Whc);
		sep_2Wcn_1Whc.forward(cg, atomFeat.sid_2Wcn, atomFeat.sid_1Whc);
		sep_2W_1Whc.forward(cg, atomFeat.sid_2W, atomFeat.sid_1Whc);
		sep_2Whc_1W.forward(cg, atomFeat.sid_2Whc, atomFeat.sid_1W);
		sep_2Wc_1WL.forward(cg, atomFeat.sid_2Whc, atomFeat.sid_1WL);
		sep_2WL_1Wc.forward(cg, atomFeat.sid_2WL, atomFeat.sid_1Whc);
		sep_2Whc_1Wcn.forward(cg, atomFeat.sid_2Whc, atomFeat.sid_1C);
		sep_1Whc_1WL.forward(cg, atomFeat.sid_1Whc, atomFeat.sid_1WL);
		pos_1Whc_1WP.forward(cg, atomFeat.sid_1Whc, atomFeat.sid_1WP);
		pos_1Whc_2WP.forward(cg, atomFeat.sid_1Whc, atomFeat.sid_2WP);
		pos_2Wcn_1Whc_1WP.forward(cg, atomFeat.sid_2Wcn, atomFeat.sid_1Whc, atomFeat.sid_1WP);
		pos_2Wcn_1Whc_n0c_1WP.forward(cg, atomFeat.sid_2Wcn, atomFeat.sid_1Whc, atomFeat.sid_C0, atomFeat.sid_1WP);
		pos_1Whc_ac.forward(cg, atomFeat.sid_1Whc);
		pos_1Whc_n0c_1WP.forward(cg, atomFeat.sid_1Whc, atomFeat.sid_C0, atomFeat.sid_1WP);
		pos_1Whc_2WP_ac.forward(cg, atomFeat.sid_1Whc, atomFeat.sid_2WP);
		pos_2Whc_1WP_ac.forward(cg, atomFeat.sid_2Whc, atomFeat.sid_1WP);

		app_1C_C0_1WP.forward(cg, atomFeat.sid_1C, atomFeat.sid_C0, atomFeat.sid_1WP);
		app_1Wc0_C0_1WP.forward(cg, atomFeat.sid_1Wc0, atomFeat.sid_C0, atomFeat.sid_1WP);
		app_2CT_1CT_CT0_1WP.forward(cg, atomFeat.sid_2CT, atomFeat.sid_1CT, atomFeat.sid_CT0, atomFeat.sid_1WP);

		//if (atomFeat.sid_1WTagD == 1)sep_1WTagD_1WP_1WL.forward(cg, atomFeat.sid_1WTagD, atomFeat.sid_1WP, atomFeat.sid_1WL);

		static vector<PNode> sumNodes;
		static CAction ac;
		static int ac_num;
		ac_num = actions.size();
		for (int idx = 0; idx < ac_num; idx++){
			ac.set(actions[idx]._code);
			sumNodes.clear();

			if (ac.isAppend()){
				if (app_1C_C0.executed)sumNodes.push_back(&app_1C_C0);
				if (app_1Wc0_C0.executed)sumNodes.push_back(&app_1Wc0_C0);
				if (app_2CT_1CT_CT0.executed)sumNodes.push_back(&app_2CT_1CT_CT0);
			}

			if (ac.isSeparate() || ac.isFinish() || ac.isIdle()){
				if (sep_1C_C0.executed)sumNodes.push_back(&sep_1C_C0);
				if (sep_1Wc0_C0.executed)sumNodes.push_back(&sep_1Wc0_C0);
				if (sep_2CT_1CT_CT0.executed)sumNodes.push_back(&sep_2CT_1CT_CT0);
				if (sep_1W.executed)sumNodes.push_back(&sep_1W);
				if (sep_1WD_1WL.executed && atomFeat.sid_1WD == 1)sumNodes.push_back(&sep_1WD_1WL);
				if (sep_1WSingle.executed && atomFeat.sid_1WL == 1)sumNodes.push_back(&sep_1WSingle);
				if (sep_1W_C0.executed)sumNodes.push_back(&sep_1W_C0);
				if (sep_2W_1W.executed)sumNodes.push_back(&sep_2W_1W);
				if (sep_2Wc0_1W.executed)sumNodes.push_back(&sep_2Wc0_1W);
				if (sep_2Wcn_1W.executed)sumNodes.push_back(&sep_2Wcn_1W);
				if (sep_2Wc0_1Wc0.executed)sumNodes.push_back(&sep_2Wc0_1Wc0);
				if (sep_2Wcn_1Wcn.executed)sumNodes.push_back(&sep_2Wcn_1Wcn);
				if (sep_2W_1WL.executed)sumNodes.push_back(&sep_2W_1WL);
				if (sep_2WL_1W.executed)sumNodes.push_back(&sep_2WL_1W);
				if (sep_2W_1Wcn.executed)sumNodes.push_back(&sep_2W_1Wcn);
				if (sep_1Wc0_1WL.executed)sumNodes.push_back(&sep_1Wc0_1WL);
				if (sep_1Wcn_1WL.executed)sumNodes.push_back(&sep_1Wcn_1WL);
				for (int idy = 0; idy < atomFeat.sid_1Wci.size() && idy < max_seg_length; idy++){
					if (sep_1Wci_1Wcn_1WP[idy].executed)sumNodes.push_back(&(sep_1Wci_1Wcn_1WP[idy]));
				}
			}

			if (atomFeat.stacksize > 1){
				if (arc_s0w_ac.executed)sumNodes.push_back(&arc_s0w_ac);
				if (arc_s0t_ac.executed)sumNodes.push_back(&arc_s0t_ac);
				if (arc_s0w_s0t_ac.executed)sumNodes.push_back(&arc_s0w_s0t_ac);
				if (arc_s1w_ac.executed)sumNodes.push_back(&arc_s1w_ac);
				if (arc_s1w_s1t_ac.executed)sumNodes.push_back(&arc_s1w_s1t_ac);
				if (arc_n0c_ac.executed)sumNodes.push_back(&arc_n0c_ac);
				if (arc_s0w_s1w_ac.executed)sumNodes.push_back(&arc_s0w_s1w_ac);
				if (arc_s0w_s1w_s0t_ac.executed)sumNodes.push_back(&arc_s0w_s1w_s0t_ac);
				if (arc_s0w_n0c_ac.executed)sumNodes.push_back(&arc_s0w_n0c_ac);
				if (arc_s0w_n0c_s0t_ac.executed)sumNodes.push_back(&arc_s0w_n0c_s0t_ac);
				if (arc_s1w_n0c_ac.executed)sumNodes.push_back(&arc_s1w_n0c_ac);
				if (arc_s1w_n0c_s0t_ac.executed)sumNodes.push_back(&arc_s1w_n0c_s0t_ac);
				if (arc_n0c_s0t_ac.executed)sumNodes.push_back(&arc_n0c_s0t_ac);
				if (arc_n0c_s0w_s1w_ac.executed)sumNodes.push_back(&arc_n0c_s0w_s1w_ac);
				if (arc_s0w_s1w_s2w_ac.executed)sumNodes.push_back(&arc_s0w_s1w_s2w_ac);
				if (arc_s0c_ac.executed)sumNodes.push_back(&arc_s0c_ac);
				if (arc_s0c_s0t_ac.executed)sumNodes.push_back(&arc_s0c_s0t_ac);
				if (arc_s1c_ac.executed)sumNodes.push_back(&arc_s1c_ac);
				if (arc_s1c_s0t_ac.executed)sumNodes.push_back(&arc_s1c_s0t_ac);
				if (arc_s0c_s1c_ac.executed)sumNodes.push_back(&arc_s0c_s1c_ac);
				if (arc_s0c_s1c_s0t_ac.executed)sumNodes.push_back(&arc_s0c_s1c_s0t_ac);
				if (arc_s0c_n0c_ac.executed)sumNodes.push_back(&arc_s0c_n0c_ac);
				if (arc_s0c_n0c_s0t_ac.executed)sumNodes.push_back(&arc_s0c_n0c_s0t_ac);
				if (arc_s1c_n0c_ac.executed)sumNodes.push_back(&arc_s1c_n0c_ac);
				if (arc_s1c_n0c_s0t_ac.executed)sumNodes.push_back(&arc_s1c_n0c_s0t_ac);
				if (arc_n0c_s0c_s1c_ac.executed)sumNodes.push_back(&arc_n0c_s0c_s1c_ac);
				if (arc_s0c_s1c_s2c_ac.executed)sumNodes.push_back(&arc_s0c_s1c_s2c_ac);

				if (arc_s0s1left_s0s1SWL_ac.executed && atomFeat.sid_s0s1arcl == 1)sumNodes.push_back(&arc_s0s1left_s0s1SWL_ac);
				if (arc_s0s1right_s0s1SWL_ac.executed && atomFeat.sid_s0s1arcr == 1)sumNodes.push_back(&arc_s0s1right_s0s1SWL_ac);
				if (arc_s0s1SWD_s0s1SWL_ac.executed && atomFeat.sid_s0s1SWD == 1)sumNodes.push_back(&arc_s0s1SWD_s0s1SWL_ac);
			}

			if (ac.isSeparate() || ac.isFinish() || ac.isIdle()){
				if (pos_1W_1WP.executed)sumNodes.push_back(&pos_1W_1WP);
				if (pos_1W_2WP.executed)sumNodes.push_back(&pos_1W_2WP);
				if (pos_2Wcn_1W_1WP.executed)sumNodes.push_back(&pos_2Wcn_1W_1WP);
				if (pos_2Wcn_1W_n0c_1WP.executed)sumNodes.push_back(&pos_2Wcn_1W_n0c_1WP);
				if (pos_1Wcn_1WP.executed)sumNodes.push_back(&pos_1Wcn_1WP);
				if (pos_1CC_1WP.executed)sumNodes.push_back(&pos_1CC_1WP);
				if (pos_1WP_ac.executed)sumNodes.push_back(&pos_1WP_ac);
				if (pos_1WL_1WP_ac.executed)sumNodes.push_back(&pos_1WL_1WP_ac);
				if (pos_1WL_1WP_2WP.executed)sumNodes.push_back(&pos_1WL_1WP_2WP);
				if (pos_1WL_1WP_2WP_ac.executed)sumNodes.push_back(&pos_1WL_1WP_2WP_ac);
				if (pos_1W_ac.executed)sumNodes.push_back(&pos_1W_ac);
				if (pos_1WP_2WP_ac.executed)sumNodes.push_back(&pos_1WP_2WP_ac);
				if (pos_1W_n0c_1WP.executed)sumNodes.push_back(&pos_1W_n0c_1WP);
				if (pos_n0c_ac.executed)sumNodes.push_back(&pos_n0c_ac);
				if (pos_CC0_ac.executed)sumNodes.push_back(&pos_CC0_ac);
				if (pos_n0c_1WP_ac.executed)sumNodes.push_back(&pos_n0c_1WP_ac);
				if (pos_n0c_1WP_2WP_ac.executed)sumNodes.push_back(&pos_n0c_1WP_2WP_ac);
				if (pos_n0c_1WP.executed)sumNodes.push_back(&pos_n0c_1WP);
				if (pos_n0c_1Wcn_1WP_ac.executed)sumNodes.push_back(&pos_n0c_1Wcn_1WP_ac);
				if (pos_1W_2WP_ac.executed)sumNodes.push_back(&pos_1W_2WP_ac);
				if (pos_2W_1WP_ac.executed)sumNodes.push_back(&pos_2W_1WP_ac);
				if (pos_1Whc_1WP.executed)sumNodes.push_back(&pos_1Whc_1WP);
				if (pos_1Whc_2WP.executed)sumNodes.push_back(&pos_1Whc_2WP);
				if (pos_2Wcn_1Whc_1WP.executed)sumNodes.push_back(&pos_2Wcn_1Whc_1WP);
				if (pos_2Wcn_1Whc_n0c_1WP.executed)sumNodes.push_back(&pos_2Wcn_1Whc_n0c_1WP);
				if (pos_1Whc_ac.executed)sumNodes.push_back(&pos_1Whc_ac);
				if (pos_1Whc_n0c_1WP.executed)sumNodes.push_back(&pos_1Whc_n0c_1WP);
				if (pos_1Whc_2WP_ac.executed)sumNodes.push_back(&pos_1Whc_2WP_ac);
				if (pos_2Whc_1WP_ac.executed)sumNodes.push_back(&pos_2Whc_1WP_ac);
				if (sep_1Whc_C0.executed)sumNodes.push_back(&sep_1Whc_C0);
				if (sep_2Whc_1Whc.executed)sumNodes.push_back(&sep_2Whc_1Whc);
				if (sep_2Wc0_1Whc.executed)sumNodes.push_back(&sep_2Wc0_1Whc);
				if (sep_2Wcn_1Whc.executed)sumNodes.push_back(&sep_2Wcn_1Whc);
				if (sep_2W_1Whc.executed)sumNodes.push_back(&sep_2W_1Whc);
				if (sep_2Whc_1W.executed)sumNodes.push_back(&sep_2Whc_1W);
				if (sep_2Wc_1WL.executed)sumNodes.push_back(&sep_2Wc_1WL);
				if (sep_2WL_1Wc.executed)sumNodes.push_back(&sep_2WL_1Wc);
				if (sep_2Whc_1Wcn.executed)sumNodes.push_back(&sep_2Whc_1Wcn);
				if (sep_1Whc_1WL.executed)sumNodes.push_back(&sep_1Whc_1WL);
			}

			if (ac.isAppend()){
				if (app_1C_C0_1WP.executed)sumNodes.push_back(&app_1C_C0_1WP);
				if (app_1Wc0_C0_1WP.executed)sumNodes.push_back(&app_1Wc0_C0_1WP);
				if (app_2CT_1CT_CT0_1WP.executed)sumNodes.push_back(&app_2CT_1CT_CT0_1WP);
			}

			if (ac.isSeparate() || ac.isFinish() || ac.isIdle()){
				//if (sep_1WTagD_1WP_1WL.executed && atomFeat.sid_1WTagD == 1)sumNodes.push_back(&sep_1WTagD_1WP_1WL);
			}
			
			if (prevStateNode != NULL){
				sumNodes.push_back(prevStateNode);
			}

			outputs[ac._code].forward(cg, sumNodes, ac._code);
		}
	}

};

#endif /* SRC_ActionedNodes_H_ */
