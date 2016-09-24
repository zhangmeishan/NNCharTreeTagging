#ifndef _JST_INSTANCE_
#define _JST_INSTANCE_


#include "N3L.h"
#include "Metric.h"
#include "Result.h"

using namespace std;

class Instance {
public:
  Instance() {
  }
  Instance(const Instance&other){
	  copyValuesFrom(other);
  }
  ~Instance() {
  }
public:
  int wordsize() const {
    return result.wordsize();
  }

  int charsize() const {
    return chars.size();
  }

  int postagsize() const {
    return result.postags.size();
  }

  void clear() {
    chars.clear();
    result.clear();
  }

  void allocate(const int& wsize, const int& csize) {
  	if(chars.size() != csize){
    	chars.resize(csize);
    }
	result.allocate(wsize, csize);
  }

  void copyValuesFrom(const Instance& anInstance) {
    allocate(anInstance.wordsize(), anInstance.charsize());
    for (int i = 0; i < anInstance.charsize(); i++) {
      chars[i] = anInstance.chars[i];
    }
	result.copyValuesFrom(anInstance.result, &chars);
  }

  inline int& head(int idx){
    return result.charheads[idx];
  }

  inline std::string& word(int idx){
    return result.words[idx];
  }

  inline std::string& tag(int idx){
	  return result.postags[idx];
  }

  inline std::string& charc(int idx){
	  return chars[idx];
  }


  void evaluate(CResult& other, Metric& segEval, Metric& tagEval, Metric& arcEval) const {
      static unordered_set<string> seggolds, taggolds, arcgolds;
      result.extractSEG(seggolds);
      result.extractPOS(taggolds);
      result.extractWS(arcgolds);

      static unordered_set<string> segpreds, tagpreds, arcpreds;
      other.extractSEG(segpreds);
      other.extractPOS(tagpreds);
      other.extractWS(arcpreds);

      static unordered_set<string>::iterator iter;
      segEval.overall_label_count += seggolds.size();
      segEval.predicated_label_count += segpreds.size();
      for (iter = segpreds.begin(); iter != segpreds.end(); iter++) {
        if (seggolds.find(*iter) != seggolds.end()) {
          segEval.correct_label_count++;
        }
      }

      tagEval.overall_label_count += taggolds.size();
      tagEval.predicated_label_count += tagpreds.size();
      for (iter = tagpreds.begin(); iter != tagpreds.end(); iter++) {
        if (taggolds.find(*iter) != taggolds.end()) {
          tagEval.correct_label_count++;
        }
      }

      arcEval.overall_label_count += arcgolds.size();
      arcEval.predicated_label_count += arcpreds.size();
      for (iter = arcpreds.begin(); iter != arcpreds.end(); iter++) {
        if (arcgolds.find(*iter) != arcgolds.end()) {
          arcEval.correct_label_count++;
        }
      }

    }


public:
  vector<string> chars;
  CResult result;
};

#endif
