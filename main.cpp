#include <iostream>
#include "DSString.h"
#include "FrequencyCollector.h"
#include "Tweet.h"
//#define CATCH_CONFIG_RUNNER

//#include <catch2/catch.hpp>

using namespace std;
using FrequencyCollector::apply_weights;

int main(int argc, char **argv) {
    auto a = apply_weights("data/train_dataset_20k.csv");
    for (const auto& x: a) {
        cout << x.first << " <> " << x.second.average() << '\n';
    }
}
