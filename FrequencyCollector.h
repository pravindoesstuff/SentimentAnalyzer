//
// Created by pravin on 1/21/22.
//

#ifndef PA01_SENTIMENT_FREQUENCYCOLLECTOR_H
#define PA01_SENTIMENT_FREQUENCYCOLLECTOR_H

#include "DSString.h"
#include "Bias.h"
#include "Tweet.h"
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

const uint16_t DATA_SIZE = 512;
namespace FrequencyCollector {
    /// Intakes DSString will apply sanitization, then tokenizes with a space delimiter, the result is a vector with every token
    vector<DSString> split_words(DSString);

    /// Goes through the file referenced by `filename` and will return an unordered map with the appropriate weights of all the words in the file of tweets
    unordered_map<DSString, Bias> apply_weights(const DSString&);

} // namespace FrequencyCollector

#endif // PA01_SENTIMENT_FREQUENCYCOLLECTOR_H
