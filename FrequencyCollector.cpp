//
// Created by pravin on 1/21/22.
//

#include "FrequencyCollector.h"
#include <vector>
#include <iostream>
#include <fstream>

using std::vector;
using std::ifstream;

vector<DSString> FrequencyCollector::split_words(DSString sentence) {
    vector<DSString> words;
    char *token = strtok(sentence.c_str(), " ");
    while (token) {
        words.emplace_back(DSString(token).cleanPunctuation());
        token = strtok(nullptr, " ");
    }
    return words;
}

void add_weights(unordered_map<DSString, Bias> &weight_map, const Tweet tweet) {
    vector<DSString> words = FrequencyCollector::split_words(tweet.tweet_body);
    for (const DSString &w: words) {
        tweet.is_positive ? weight_map[w].add_positive() : weight_map[w].add_negative();
    }
}

unordered_map<DSString, Bias> FrequencyCollector::apply_weights(DSString filename) {
    ifstream file(filename.c_str());
    unordered_map<DSString, Bias> weights;
    file.ignore(DATA_SIZE, '\n');
    while (!file.eof()) {
        char line[DATA_SIZE];
        file.getline(line, DATA_SIZE);
        Tweet tweet(line);
        add_weights(weights, tweet);
    }
    return weights;
}