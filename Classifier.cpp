//
// Created by pravin on 2/8/22.
//

#include "Classifier.h"
#include "FrequencyCollector.h"
#include <iostream>
#include <fstream>

using std::ifstream;

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

unordered_map<uint32_t, bool>
Classifier::classify_tweets(const DSString &filename, const unordered_map<DSString, Bias> &model) {
    unordered_map<uint32_t, bool> ranks;
    ifstream file(filename.c_str());
    file.ignore(DATA_SIZE, '\n');
    char line[DATA_SIZE];
    while (file.getline(line, DATA_SIZE) && line[0] != '\0') {
        Tweet t(false, line);
        double weight = string_weight(t.tweet_body, model);
        ranks[t.id] = weight > 0.5;
    }
    return ranks;
}

double
Classifier::compute_accuracy(const DSString &sentiment_file, const unordered_map<uint32_t, bool> &classifications) {
    ifstream file(sentiment_file.c_str());
    file.ignore(DATA_SIZE, '\n');
    char line[DATA_SIZE];
    size_t accurate_hits = 0, total = 0;
    while (file.getline(line, DATA_SIZE) && line[0] != '\0') {
        bool sentiment = line[0] - '0';
        uint32_t id = DSString(line).substring(2, 10).as_uint();
        accurate_hits += classifications.at(id) == sentiment;
        ++total;
    }
    return (double) accurate_hits / (double) total;
}