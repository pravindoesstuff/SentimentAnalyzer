#include <iostream>
#include "FrequencyCollector.h"
#include "Classifier.h"
//#define CATCH_CONFIG_RUNNER

//#include <catch2/catch.hpp>

using namespace std;
using FrequencyCollector::apply_weights;

int main(int argc, char **argv) {
    auto model = apply_weights("data/train_dataset_20k.csv");
    auto classification = Classifier::classify_tweets("data/test_dataset_10k.csv", model);
    for (auto c: classification) {
        cout << c.first << ":" << (c.second ? 4 : 0) << '\n';
    }
}