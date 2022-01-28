//
// Created by pravin on 1/21/22.
//

#include "FrequencyCollector.h"
#include <vector>
#include <fstream>

using std::vector, std::ifstream;

vector<DSString> FrequencyCollector::split_words(DSString sentence) {
    vector<DSString> words;
    char *token = strtok(sentence.c_str(), " ");
    while (token) {
        words.emplace_back(DSString(token).cleanPunctuation());
        token = strtok(nullptr, " ");
    }
    return words;
}

unordered_map<DSString, Bias> apply_weights(DSString filename) {
    vector<DSString> tweet_lines;
    ifstream file(filename.c_str());
    while (!file.eof()) {
        char line[DATA_SIZE];
        file.getline(line, DATA_SIZE);
        tweet_lines.emplace_back(line);
    }
}