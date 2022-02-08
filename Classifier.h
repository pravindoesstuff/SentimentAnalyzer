//
// Created by pravin on 2/8/22.
//

#ifndef PA01_SENTIMENT_CLASSIFIER_H
#define PA01_SENTIMENT_CLASSIFIER_H

#include "DSString.h"
#include "Bias.h"
#include <unordered_map>

using std::unordered_map;

namespace Classifier {
    double string_weight(DSString ds_string, const unordered_map<DSString, Bias> &model);

    unordered_map<uint32_t, bool> classify_tweets(const DSString &, const unordered_map<DSString, Bias> &);

    double compute_accuracy(const DSString &, const unordered_map<uint32_t, bool> &);
}


#endif //PA01_SENTIMENT_CLASSIFIER_H
