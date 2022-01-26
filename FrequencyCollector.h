//
// Created by pravin on 1/21/22.
//

#ifndef PA01_SENTIMENT_FREQUENCYCOLLECTOR_H
#define PA01_SENTIMENT_FREQUENCYCOLLECTOR_H
#include "DSString.h"
#include <unordered_map>
#include <vector>
using std::vector;

namespace FrequencyCollector {
/// Returns a DSString[] of all the separated words within another DSString
vector<DSString> split_words(DSString);
}; // namespace FrequencyCollector

#endif // PA01_SENTIMENT_FREQUENCYCOLLECTOR_H
