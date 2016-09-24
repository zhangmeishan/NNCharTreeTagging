#ifndef _CONLL_READER_
#define _CONLL_READER_

#include "Reader.h"
#include "N3L.h"
#include "Utf.h"
#include <sstream>

using namespace std;
/*
 this class reads conll-format data (10 columns, no srl-info)
 */
class InstanceReader: public Reader {
public:
  InstanceReader() {
  }
  ~InstanceReader() {
  }

  Instance *getNext() {
    m_instance.clear();
    static string strLine;
    static vector<string> vecLine;
	vecLine.clear();
    while (1) {
      if (!my_getline(m_inf, strLine)) {
        break;
      }
      if (strLine.empty())
        break;
      vecLine.push_back(strLine);
    }

	static vector<string> charInfo;
	static int count, parent_id;
	count = 0;
    for (int i = 0; i < vecLine.size(); i++) {
      split_bychar(vecLine[i], charInfo, '\t');
	  m_instance.chars.push_back(charInfo[0]);
	  m_instance.result.charlabels.push_back(charInfo[2]);

	  if (i == 0 || charInfo[2] == "b") {
		m_instance.result.words.push_back(charInfo[0]);
		m_instance.result.postags.push_back(charInfo[1]);		
		count++;
      }
	  else{
		  m_instance.word(count - 1) = m_instance.word(count - 1) + charInfo[0];
	  }

	  if (charInfo[4] == "-NONE-"){
		  m_instance.result.charheads.push_back(atoi(charInfo[3].c_str()));
	  }
	  else{		  
		  m_instance.result.charheads.push_back(-1);
	  }
    }

	m_instance.result.chars = &m_instance.chars;

    return &m_instance;
  }
};

#endif

