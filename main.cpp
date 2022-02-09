#include <iostream>
#include "FrequencyCollector.h"
#include "Classifier.h"

#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

using namespace std;
using FrequencyCollector::apply_weights;

int main(int argc, char **argv) {
    if (argc == 1) return Catch::Session().run();
    auto model = apply_weights(argv[1]);
    auto classification = Classifier::classify_tweets(argv[2], model);
    cout << Classifier::write_accuracy(argv[3], argv[4], classification);
}