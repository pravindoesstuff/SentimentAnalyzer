#include <iostream>
#include "DSString.h"
#include "FrequencyCollector.h"
#include "Tweet.h"
#include "Classifier.h"
//#define CATCH_CONFIG_RUNNER

//#include <catch2/catch.hpp>

using namespace std;
using FrequencyCollector::apply_weights;

int main(int argc, char **argv) {
    auto a = apply_weights("data/train_dataset_20k.csv");
    auto p1 = Classifier::string_weight("I love the president of the United States", a);
    auto p2 = Classifier::string_weight("I hate the president of the United States", a);
    cout << p1 << ' ' << p2 << endl;
}
