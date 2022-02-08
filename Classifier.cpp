//
// Created by pravin on 2/8/22.
//

#include "Classifier.h"
#include "FrequencyCollector.h"

double Classifier::string_weight(DSString ds_string, const unordered_map<DSString, Bias> &model) {
    ds_string.sanitize();
    vector<DSString> words = FrequencyCollector::split_words(ds_string);
    double rank_total = 0;
    double rank_count = 0;
    for (const DSString &word: words) {
        if (model.count(word)) {
            double weight = model.at(word).average();
            double multiplier = std::abs(weight - 0.5); //Reward polarizing words, penalize generalized words
            rank_total += weight * multiplier;
            rank_count += multiplier;
        }
    }
    return rank_total / rank_count;
}

unordered_map<size_t, bool> Classifier::classify_tweets(DSString filename) {

}