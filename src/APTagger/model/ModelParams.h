#ifndef SRC_ModelParams_H_
#define SRC_ModelParams_H_
#include "HyperParams.h"

// Each model consists of two parts, building neural graph and defining output losses.
class ModelParams{

public:
	//should be initialized outside
	Alphabet words; // words
	Alphabet subwords; // words
	Alphabet chars; // chars
	Alphabet charTypes; // char type
	Alphabet charCats; // char type

	//feature templates
	//append feature parameters
	APC2Params  app_1C_C0;
	APC2Params  app_1Wc0_C0;
	APC3Params  app_2CT_1CT_CT0;

	//separate feature parameters
	APC2Params  sep_1C_C0;
	APC2Params  sep_1Wc0_C0;
	APC3Params  sep_2CT_1CT_CT0;
	APC1Params  sep_1W;
	APC2Params  sep_1WD_1WL;
	APC1Params  sep_1WSingle;
	APC2Params  sep_1W_C0;
	APC2Params  sep_2W_1W;
	APC2Params  sep_2Wc0_1W;
	APC2Params  sep_2Wcn_1W;
	APC2Params  sep_2Wc0_1Wc0;
	APC2Params  sep_2Wcn_1Wcn;
	APC2Params  sep_2W_1WL;
	APC2Params  sep_2WL_1W;
	APC2Params  sep_2W_1Wcn;
	APC2Params  sep_1Wc0_1WL;
	APC2Params  sep_1Wcn_1WL;
	APC3Params  sep_1Wci_1Wcn_1WP;

	//character structure features
	//arc features
	APC1Params arc_s0w_ac;
	APC1Params arc_s0t_ac;
	APC2Params arc_s0w_s0t_ac;

	APC1Params arc_s1w_ac;
	APC2Params arc_s1w_s1t_ac;

	APC1Params arc_n0c_ac;

	APC2Params arc_s0w_s1w_ac;
	APC3Params arc_s0w_s1w_s0t_ac;

	APC2Params arc_s0w_n0c_ac;
	APC3Params arc_s0w_n0c_s0t_ac;

	APC2Params arc_s1w_n0c_ac;
	APC3Params arc_s1w_n0c_s0t_ac;

	APC2Params arc_n0c_s0t_ac;

	APC3Params arc_n0c_s0w_s1w_ac;
	APC3Params arc_s0w_s1w_s2w_ac;

	APC1Params arc_s0c_ac;
	APC2Params arc_s0c_s0t_ac;

	APC1Params arc_s1c_ac;
	APC2Params arc_s1c_s0t_ac;

	APC2Params arc_s0c_s1c_ac;
	APC3Params arc_s0c_s1c_s0t_ac;

	APC2Params arc_s0c_n0c_ac;
	APC3Params arc_s0c_n0c_s0t_ac;

	APC2Params arc_s1c_n0c_ac;
	APC3Params arc_s1c_n0c_s0t_ac;

	APC3Params arc_n0c_s0c_s1c_ac;
	APC3Params arc_s0c_s1c_s2c_ac;

	//tagging features
	//sep
	APC2Params pos_1W_1WP;
	APC2Params pos_1W_2WP;
	APC3Params pos_2Wcn_1W_1WP;
	APC4Params pos_2Wcn_1W_n0c_1WP;
	APC2Params pos_1Wcn_1WP;
	APC2Params pos_1CC_1WP;

	APC1Params pos_1WP_ac;
	APC2Params pos_1WL_1WP_ac;
	APC3Params pos_1WL_1WP_2WP;
	APC3Params pos_1WL_1WP_2WP_ac;

	APC1Params pos_1W_ac;
	APC2Params pos_1WP_2WP_ac;
	APC3Params pos_1W_n0c_1WP;

	APC1Params pos_n0c_ac;
	APC1Params pos_CC0_ac;

	APC2Params pos_n0c_1WP_ac;
	APC3Params pos_n0c_1WP_2WP_ac;

	APC2Params pos_n0c_1WP;

	APC3Params pos_n0c_1Wcn_1WP_ac;

	APC2Params pos_1W_2WP_ac;
	APC2Params pos_2W_1WP_ac;

	//append
	APC3Params  app_1C_C0_1WP;
	APC3Params  app_1Wc0_C0_1WP;
	APC4Params  app_2CT_1CT_CT0_1WP;


	//character structure features
	//segmentation
	APC2Params  sep_1Whc_C0;
	APC2Params  sep_2Whc_1Whc;
	APC2Params  sep_2Wc0_1Whc;
	APC2Params  sep_2Wcn_1Whc;
	APC2Params  sep_2W_1Whc;
	APC2Params  sep_2Whc_1W;
	APC2Params  sep_2Wc_1WL;
	APC2Params  sep_2WL_1Wc;
	APC2Params  sep_2Whc_1Wcn;
	APC2Params  sep_1Whc_1WL;

	//tagging
	APC2Params pos_1Whc_1WP;
	APC2Params pos_1Whc_2WP;
	APC3Params pos_2Wcn_1Whc_1WP;
	APC4Params pos_2Wcn_1Whc_n0c_1WP;

	APC1Params pos_1Whc_ac;
	APC3Params pos_1Whc_n0c_1WP;

	APC2Params pos_1Whc_2WP_ac;
	APC2Params pos_2Whc_1WP_ac;


	//some dictionary-based arc features
	APC2Params arc_s0s1left_s0s1SWL_ac;
	APC2Params arc_s0s1right_s0s1SWL_ac;
	APC2Params arc_s0s1SWD_s0s1SWL_ac;


public:
	bool initial(HyperParams& opts){
		// some model parameters should be initialized outside
		if (words.size() <= 0 || chars.size() <= 0 || charTypes.size() <= 0 || subwords.size() <= 0){
			return false;
		}
		app_1C_C0.initial();
		app_1Wc0_C0.initial();
		app_2CT_1CT_CT0.initial();

		sep_1C_C0.initial();
		sep_1Wc0_C0.initial();
		sep_2CT_1CT_CT0.initial();
		sep_1W.initial();
		sep_1WD_1WL.initial();
		sep_1WSingle.initial();
		sep_1W_C0.initial();
		sep_2W_1W.initial();
		sep_2Wc0_1W.initial();
		sep_2Wcn_1W.initial();
		sep_2Wc0_1Wc0.initial();
		sep_2Wcn_1Wcn.initial();
		sep_2W_1WL.initial();
		sep_2WL_1W.initial();
		sep_2W_1Wcn.initial();
		sep_1Wc0_1WL.initial();
		sep_1Wcn_1WL.initial();
		sep_1Wci_1Wcn_1WP.initial();

		arc_s0w_ac.initial(opts.action_num);
		arc_s0t_ac.initial(opts.action_num);
		arc_s0w_s0t_ac.initial(opts.action_num);
		arc_s1w_ac.initial(opts.action_num);
		arc_s1w_s1t_ac.initial(opts.action_num);
		arc_n0c_ac.initial(opts.action_num);
		arc_s0w_s1w_ac.initial(opts.action_num);
		arc_s0w_s1w_s0t_ac.initial(opts.action_num);
		arc_s0w_n0c_ac.initial(opts.action_num);
		arc_s0w_n0c_s0t_ac.initial(opts.action_num);
		arc_s1w_n0c_ac.initial(opts.action_num);
		arc_s1w_n0c_s0t_ac.initial(opts.action_num);
		arc_n0c_s0t_ac.initial(opts.action_num);
		arc_n0c_s0w_s1w_ac.initial(opts.action_num);
		arc_s0w_s1w_s2w_ac.initial(opts.action_num);
		arc_s0c_ac.initial(opts.action_num);
		arc_s0c_s0t_ac.initial(opts.action_num);
		arc_s1c_ac.initial(opts.action_num);
		arc_s1c_s0t_ac.initial(opts.action_num);
		arc_s0c_s1c_ac.initial(opts.action_num);
		arc_s0c_s1c_s0t_ac.initial(opts.action_num);
		arc_s0c_n0c_ac.initial(opts.action_num);
		arc_s0c_n0c_s0t_ac.initial(opts.action_num);
		arc_s1c_n0c_ac.initial(opts.action_num);
		arc_s1c_n0c_s0t_ac.initial(opts.action_num);
		arc_n0c_s0c_s1c_ac.initial(opts.action_num);
		arc_s0c_s1c_s2c_ac.initial(opts.action_num);
		pos_1W_1WP.initial();
		pos_1W_2WP.initial();
		pos_2Wcn_1W_1WP.initial();
		pos_2Wcn_1W_n0c_1WP.initial();
		pos_1Wcn_1WP.initial();
		pos_1CC_1WP.initial();
		pos_1WP_ac.initial(opts.action_num);
		pos_1WL_1WP_ac.initial(opts.action_num);
		pos_1WL_1WP_2WP.initial();
		pos_1WL_1WP_2WP_ac.initial(opts.action_num);
		pos_1W_ac.initial(opts.action_num);
		pos_1WP_2WP_ac.initial(opts.action_num);
		pos_1W_n0c_1WP.initial();
		pos_n0c_ac.initial(opts.action_num);
		pos_CC0_ac.initial(opts.action_num);
		pos_n0c_1WP_ac.initial(opts.action_num);
		pos_n0c_1WP_2WP_ac.initial(opts.action_num);
		pos_n0c_1WP.initial();
		pos_n0c_1Wcn_1WP_ac.initial(opts.action_num);
		pos_1W_2WP_ac.initial(opts.action_num);
		pos_2W_1WP_ac.initial(opts.action_num);
		app_1C_C0_1WP.initial();
		app_1Wc0_C0_1WP.initial();
		app_2CT_1CT_CT0_1WP.initial();
		sep_1Whc_C0.initial();
		sep_2Whc_1Whc.initial();
		sep_2Wc0_1Whc.initial();
		sep_2Wcn_1Whc.initial();
		sep_2W_1Whc.initial();
		sep_2Whc_1W.initial();
		sep_2Wc_1WL.initial();
		sep_2WL_1Wc.initial();
		sep_2Whc_1Wcn.initial();
		sep_1Whc_1WL.initial();
		pos_1Whc_1WP.initial();
		pos_1Whc_2WP.initial();
		pos_2Wcn_1Whc_1WP.initial();
		pos_2Wcn_1Whc_n0c_1WP.initial();
		pos_1Whc_ac.initial(opts.action_num);
		pos_1Whc_n0c_1WP.initial();
		pos_1Whc_2WP_ac.initial(opts.action_num);
		pos_2Whc_1WP_ac.initial(opts.action_num);


		arc_s0s1left_s0s1SWL_ac.initial(opts.action_num);
		arc_s0s1right_s0s1SWL_ac.initial(opts.action_num);
		arc_s0s1SWD_s0s1SWL_ac.initial(opts.action_num);

		return true;
	}


	void exportModelParams(ModelUpdate& ada){
		app_1C_C0.exportAdaParams(ada);
		app_1Wc0_C0.exportAdaParams(ada);
		app_2CT_1CT_CT0.exportAdaParams(ada);

		sep_1C_C0.exportAdaParams(ada);
		sep_1Wc0_C0.exportAdaParams(ada);
		sep_2CT_1CT_CT0.exportAdaParams(ada);
		sep_1W.exportAdaParams(ada);
		sep_1WD_1WL.exportAdaParams(ada);
		sep_1WSingle.exportAdaParams(ada);
		sep_1W_C0.exportAdaParams(ada);
		sep_2W_1W.exportAdaParams(ada);
		sep_2Wc0_1W.exportAdaParams(ada);
		sep_2Wcn_1W.exportAdaParams(ada);
		sep_2Wc0_1Wc0.exportAdaParams(ada);
		sep_2Wcn_1Wcn.exportAdaParams(ada);
		sep_2W_1WL.exportAdaParams(ada);
		sep_2WL_1W.exportAdaParams(ada);
		sep_2W_1Wcn.exportAdaParams(ada);
		sep_1Wc0_1WL.exportAdaParams(ada);
		sep_1Wcn_1WL.exportAdaParams(ada);
		sep_1Wci_1Wcn_1WP.exportAdaParams(ada);

		arc_s0w_ac.exportAdaParams(ada);
		arc_s0t_ac.exportAdaParams(ada);
		arc_s0w_s0t_ac.exportAdaParams(ada);
		arc_s1w_ac.exportAdaParams(ada);
		arc_s1w_s1t_ac.exportAdaParams(ada);
		arc_n0c_ac.exportAdaParams(ada);
		arc_s0w_s1w_ac.exportAdaParams(ada);
		arc_s0w_s1w_s0t_ac.exportAdaParams(ada);
		arc_s0w_n0c_ac.exportAdaParams(ada);
		arc_s0w_n0c_s0t_ac.exportAdaParams(ada);
		arc_s1w_n0c_ac.exportAdaParams(ada);
		arc_s1w_n0c_s0t_ac.exportAdaParams(ada);
		arc_n0c_s0t_ac.exportAdaParams(ada);
		arc_n0c_s0w_s1w_ac.exportAdaParams(ada);
		arc_s0w_s1w_s2w_ac.exportAdaParams(ada);
		arc_s0c_ac.exportAdaParams(ada);
		arc_s0c_s0t_ac.exportAdaParams(ada);
		arc_s1c_ac.exportAdaParams(ada);
		arc_s1c_s0t_ac.exportAdaParams(ada);
		arc_s0c_s1c_ac.exportAdaParams(ada);
		arc_s0c_s1c_s0t_ac.exportAdaParams(ada);
		arc_s0c_n0c_ac.exportAdaParams(ada);
		arc_s0c_n0c_s0t_ac.exportAdaParams(ada);
		arc_s1c_n0c_ac.exportAdaParams(ada);
		arc_s1c_n0c_s0t_ac.exportAdaParams(ada);
		arc_n0c_s0c_s1c_ac.exportAdaParams(ada);
		arc_s0c_s1c_s2c_ac.exportAdaParams(ada);
		pos_1W_1WP.exportAdaParams(ada);
		pos_1W_2WP.exportAdaParams(ada);
		pos_2Wcn_1W_1WP.exportAdaParams(ada);
		pos_2Wcn_1W_n0c_1WP.exportAdaParams(ada);
		pos_1Wcn_1WP.exportAdaParams(ada);
		pos_1CC_1WP.exportAdaParams(ada);
		pos_1WP_ac.exportAdaParams(ada);
		pos_1WL_1WP_ac.exportAdaParams(ada);
		pos_1WL_1WP_2WP.exportAdaParams(ada);
		pos_1WL_1WP_2WP_ac.exportAdaParams(ada);
		pos_1W_ac.exportAdaParams(ada);
		pos_1WP_2WP_ac.exportAdaParams(ada);
		pos_1W_n0c_1WP.exportAdaParams(ada);
		pos_n0c_ac.exportAdaParams(ada);
		pos_CC0_ac.exportAdaParams(ada);
		pos_n0c_1WP_ac.exportAdaParams(ada);
		pos_n0c_1WP_2WP_ac.exportAdaParams(ada);
		pos_n0c_1WP.exportAdaParams(ada);
		pos_n0c_1Wcn_1WP_ac.exportAdaParams(ada);
		pos_1W_2WP_ac.exportAdaParams(ada);
		pos_2W_1WP_ac.exportAdaParams(ada);
		app_1C_C0_1WP.exportAdaParams(ada);
		app_1Wc0_C0_1WP.exportAdaParams(ada);
		app_2CT_1CT_CT0_1WP.exportAdaParams(ada);
		sep_1Whc_C0.exportAdaParams(ada);
		sep_2Whc_1Whc.exportAdaParams(ada);
		sep_2Wc0_1Whc.exportAdaParams(ada);
		sep_2Wcn_1Whc.exportAdaParams(ada);
		sep_2W_1Whc.exportAdaParams(ada);
		sep_2Whc_1W.exportAdaParams(ada);
		sep_2Wc_1WL.exportAdaParams(ada);
		sep_2WL_1Wc.exportAdaParams(ada);
		sep_2Whc_1Wcn.exportAdaParams(ada);
		sep_1Whc_1WL.exportAdaParams(ada);
		pos_1Whc_1WP.exportAdaParams(ada);
		pos_1Whc_2WP.exportAdaParams(ada);
		pos_2Wcn_1Whc_1WP.exportAdaParams(ada);
		pos_2Wcn_1Whc_n0c_1WP.exportAdaParams(ada);
		pos_1Whc_ac.exportAdaParams(ada);
		pos_1Whc_n0c_1WP.exportAdaParams(ada);
		pos_1Whc_2WP_ac.exportAdaParams(ada);
		pos_2Whc_1WP_ac.exportAdaParams(ada);


		arc_s0s1left_s0s1SWL_ac.exportAdaParams(ada);
		arc_s0s1right_s0s1SWL_ac.exportAdaParams(ada);
		arc_s0s1SWD_s0s1SWL_ac.exportAdaParams(ada);
	}


	inline void setFixed(const int& base = 1){
		app_1C_C0.setFixed(base);
		app_1Wc0_C0.setFixed(base);
		app_2CT_1CT_CT0.setFixed(base);

		sep_1C_C0.setFixed(base);
		sep_1Wc0_C0.setFixed(base);
		sep_2CT_1CT_CT0.setFixed(base);
		sep_1W.setFixed(base);
		sep_1WD_1WL.setFixed(base);
		sep_1WSingle.setFixed(base);
		sep_1W_C0.setFixed(base);
		sep_2W_1W.setFixed(base);
		sep_2Wc0_1W.setFixed(base);
		sep_2Wcn_1W.setFixed(base);
		sep_2Wc0_1Wc0.setFixed(base);
		sep_2Wcn_1Wcn.setFixed(base);
		sep_2W_1WL.setFixed(base);
		sep_2WL_1W.setFixed(base);
		sep_2W_1Wcn.setFixed(base);
		sep_1Wc0_1WL.setFixed(base);
		sep_1Wcn_1WL.setFixed(base);
		sep_1Wci_1Wcn_1WP.setFixed(base);

		arc_s0w_ac.setFixed(base);
		arc_s0t_ac.setFixed(base);
		arc_s0w_s0t_ac.setFixed(base);
		arc_s1w_ac.setFixed(base);
		arc_s1w_s1t_ac.setFixed(base);
		arc_n0c_ac.setFixed(base);
		arc_s0w_s1w_ac.setFixed(base);
		arc_s0w_s1w_s0t_ac.setFixed(base);
		arc_s0w_n0c_ac.setFixed(base);
		arc_s0w_n0c_s0t_ac.setFixed(base);
		arc_s1w_n0c_ac.setFixed(base);
		arc_s1w_n0c_s0t_ac.setFixed(base);
		arc_n0c_s0t_ac.setFixed(base);
		arc_n0c_s0w_s1w_ac.setFixed(base);
		arc_s0w_s1w_s2w_ac.setFixed(base);
		arc_s0c_ac.setFixed(base);
		arc_s0c_s0t_ac.setFixed(base);
		arc_s1c_ac.setFixed(base);
		arc_s1c_s0t_ac.setFixed(base);
		arc_s0c_s1c_ac.setFixed(base);
		arc_s0c_s1c_s0t_ac.setFixed(base);
		arc_s0c_n0c_ac.setFixed(base);
		arc_s0c_n0c_s0t_ac.setFixed(base);
		arc_s1c_n0c_ac.setFixed(base);
		arc_s1c_n0c_s0t_ac.setFixed(base);
		arc_n0c_s0c_s1c_ac.setFixed(base);
		arc_s0c_s1c_s2c_ac.setFixed(base);
		pos_1W_1WP.setFixed(base);
		pos_1W_2WP.setFixed(base);
		pos_2Wcn_1W_1WP.setFixed(base);
		pos_2Wcn_1W_n0c_1WP.setFixed(base);
		pos_1Wcn_1WP.setFixed(base);
		pos_1CC_1WP.setFixed(base);
		pos_1WP_ac.setFixed(base);
		pos_1WL_1WP_ac.setFixed(base);
		pos_1WL_1WP_2WP.setFixed(base);
		pos_1WL_1WP_2WP_ac.setFixed(base);
		pos_1W_ac.setFixed(base);
		pos_1WP_2WP_ac.setFixed(base);
		pos_1W_n0c_1WP.setFixed(base);
		pos_n0c_ac.setFixed(base);
		pos_CC0_ac.setFixed(base);
		pos_n0c_1WP_ac.setFixed(base);
		pos_n0c_1WP_2WP_ac.setFixed(base);
		pos_n0c_1WP.setFixed(base);
		pos_n0c_1Wcn_1WP_ac.setFixed(base);
		pos_1W_2WP_ac.setFixed(base);
		pos_2W_1WP_ac.setFixed(base);
		app_1C_C0_1WP.setFixed(base);
		app_1Wc0_C0_1WP.setFixed(base);
		app_2CT_1CT_CT0_1WP.setFixed(base);
		sep_1Whc_C0.setFixed(base);
		sep_2Whc_1Whc.setFixed(base);
		sep_2Wc0_1Whc.setFixed(base);
		sep_2Wcn_1Whc.setFixed(base);
		sep_2W_1Whc.setFixed(base);
		sep_2Whc_1W.setFixed(base);
		sep_2Wc_1WL.setFixed(base);
		sep_2WL_1Wc.setFixed(base);
		sep_2Whc_1Wcn.setFixed(base);
		sep_1Whc_1WL.setFixed(base);
		pos_1Whc_1WP.setFixed(base);
		pos_1Whc_2WP.setFixed(base);
		pos_2Wcn_1Whc_1WP.setFixed(base);
		pos_2Wcn_1Whc_n0c_1WP.setFixed(base);
		pos_1Whc_ac.setFixed(base);
		pos_1Whc_n0c_1WP.setFixed(base);
		pos_1Whc_2WP_ac.setFixed(base);
		pos_2Whc_1WP_ac.setFixed(base);

		arc_s0s1left_s0s1SWL_ac.setFixed(base);
		arc_s0s1right_s0s1SWL_ac.setFixed(base);
		arc_s0s1SWD_s0s1SWL_ac.setFixed(base);
	}

	// will add it later
	void saveModel(){

	}

	void loadModel(const string& inFile){

	}

};

#endif /* SRC_ModelParams_H_ */