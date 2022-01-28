//
// Created by pravin on 1/21/22.
//

#ifndef PA01_SENTIMENT_FREQUENCYCOLLECTOR_H
#define PA01_SENTIMENT_FREQUENCYCOLLECTOR_H

#include "DSString.h"
#include "Bias.h"
#include <unordered_map>
#include <vector>

using std::vector, std::unordered_map, std::tuple;

const uint16_t DATA_SIZE = 512;
namespace FrequencyCollector {
/// Returns a DSString[] of all the separated words within another DSString
    vector<DSString> split_words(DSString);

    unordered_map<DSString, Bias> apply_weights(DSString filename);

}; // namespace FrequencyCollector

#endif // PA01_SENTIMENT_FREQUENCYCOLLECTOR_H
