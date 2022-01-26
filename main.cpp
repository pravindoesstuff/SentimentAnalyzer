#include <iostream>
#include "DSString.h"
#include "FrequencyCollector.h"

//#define CATCH_CONFIG_RUNNER

//#include <catch2/catch.hpp>

using namespace std;

int main(int argc, char **argv) {
    DSString string = "Hello, my name is: Pravin. Wow!";
    auto vec = FrequencyCollector::split_words(string);
    for (const DSString& v: vec) {
        cout << v << '\n';
    }
}
