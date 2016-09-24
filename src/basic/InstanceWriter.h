#ifndef _CONLL_WRITER_
#define _CONLL_WRITER_

#include "Writer.h"
#include "MyLib.h"
#include <sstream>

using namespace std;

class InstanceWriter : public Writer
{
public:
	InstanceWriter(){}
	~InstanceWriter(){}
	int write(const Instance *pInstance)
	{
	  if (!m_outf.is_open()) return -1;
	  static int word_index;
	  word_index = -1;
	  for (int i = 0; i < pInstance->charsize(); ++i) {
		  if (i == 0 || pInstance->result.charlabels[i] == "b"){
			  word_index++;
		  }
		  m_outf << pInstance->chars[i] << " " << pInstance->result.postags[word_index] << " " << pInstance->result.charlabels[i] << " " << pInstance->result.charheads[i];

		  if (pInstance->result.charheads[i] < 0){
			  m_outf << " ROOT out" << std::endl;
		  }
		  else{
			  m_outf << " -NONE- in" << std::endl;
		  }
	  }
	  m_outf << endl;
	  return 0;
	}

  int write(const CResult& result)
  {
    if (!m_outf.is_open())
      return -1;
	static int word_index;
	word_index = -1;
	for (int i = 0; i < result.charsize(); ++i) {
		if (i == 0 || result.charlabels[i] == "b"){
			word_index++;
		}
		m_outf << (*result.chars)[i] << " " << result.postags[word_index] << " " << result.charlabels[i] << " " << result.charheads[i];

		if (result.charheads[i] < 0){
			m_outf << " ROOT out" << std::endl;
		}
		else{
			m_outf << " -NONE- in" << std::endl;
		}
	}
    m_outf << endl;
    return 0;
  }
};

#endif

