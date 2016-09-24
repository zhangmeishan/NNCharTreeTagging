/*
 * Tag.h
 *
 *  Created on: Apr 23, 2016
 *      Author: panda
 */

#ifndef BASIC_TAG_H_
#define BASIC_TAG_H_

#include "MyLib.h"

class CTag {
public:
	const static int TAG_SIZE = 33;
	const static string TAG_STRING[TAG_SIZE];
	const static bool TAG_CLOSED[TAG_SIZE];
public:
	static inline int getID(const string& tag){
		for (int idx = 0; idx < TAG_SIZE; idx++){
			if (TAG_STRING[idx] == tag){
				return idx;
			}
		}
		return -1;
	}
};

const string CTag::TAG_STRING[TAG_SIZE] = {
	"NN", "VV",
	"NR", "AD",
	"P", "CD", "M", "JJ",
	"DEC", "DEG",
	"NT", "CC", "VA", "LC",
	"PN", "DT", "VC", "AS", "VE",
	"OD", "IJ", "ON",
	"ETC", "MSP", "CS", "BA",
	"DEV", "SB", "SP", "LB",
	"FW", "DER", "PU",
};


const  bool CTag::TAG_CLOSED[TAG_SIZE] = {
	false, false,
	false, false,
	true, false, false, false,
	true, true,
	false, true, false, true,
	true, true, true, true, true,
	false, true, true,
	true, true, true, true,
	true, true, true, true,
	false, true, true,
};


#endif /* BASIC_TAG_H_ */
