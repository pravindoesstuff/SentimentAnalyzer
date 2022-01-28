//
// Created by pravin on 1/21/22.
//

#include "FrequencyCollector.h"
#include <vector>

using std::vector;

vector<DSString> FrequencyCollector::split_words(DSString sentence) {
    vector<DSString> words;
    char *token = strtok(sentence.c_str(), " ");
    while (token) {
        words.emplace_back(DSString(token).cleanPunctuation());
        token = strtok(nullptr, " ");
    }
    return words;
}

unordered_map<DSString, tuple<int, int>> apply_weights(DSString filename) {

}