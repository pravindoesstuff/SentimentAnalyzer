//
// Created by pravin on 2/8/22.
//

#include "Classifier.h"
#include "FrequencyCollector.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;

double Classifier::string_weight(DSString ds_string, const unordered_map<DSString, Bias> &model) {
    ds_string.sanitize();
    ds_string.remove_adjacent_letters();
    vector<DSString> words = FrequencyCollector::split_words(ds_string);
    double rank_total = 0, rank_count = 0;
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
Classifier::write_accuracy(const DSString &sentiment_file, const DSString &output_filename,
                           unordered_map<uint32_t, bool> &classifications) {
    ifstream input_file(sentiment_file.c_str());
    input_file.ignore(DATA_SIZE, '\n');
    char line[DATA_SIZE];
    size_t accurate_hits = 0, total = 0;
    vector<uint32_t> misses;
    while (input_file.getline(line, DATA_SIZE) && line[0] != '\0') {
        bool sentiment = line[0] - '0';
        uint32_t id = DSString(line).substring(2, 10).as_uint();
        bool result = classifications.at(id) == sentiment;
        ++total;
        accurate_hits += result;
        if (!result) misses.emplace_back(id);
    }
    double accuracy = (double) accurate_hits / (double) total;
    ofstream output_file(output_filename.c_str());
    output_file << accuracy << '\n';
    for (uint32_t id: misses) output_file << id << '\n'; //write all the missed ids to the output file
    return accuracy;
}