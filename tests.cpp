//
// Created by pravin on 2/9/22.
//

#include "catch.hpp"
#include "DSString.h"
#include "FrequencyCollector.h"

TEST_CASE("split_words works correctly") {
    DSString d = "the quick brown fox jumped over the lazy dog";
    vector<DSString> w1 = {"the", "quick", "brown", "fox", "jumped", "over", "the", "lazy", "dog"};
    vector<DSString> w2 = FrequencyCollector::split_words(d);
    REQUIRE(w1 == w2);
}

TEST_CASE("DSString sanitizer works correctly") {
    DSString d = "H3LL0 W0R|D";
    d.sanitize();
    REQUIRE(d == "h ll  w r d");
}

TEST_CASE("Assignment operations", "[DSString]") {
    DSString d = "Hello World";
    SECTION("Copy assignment operator") {
        DSString e = d;
        d[0]; // This does nothing
        REQUIRE(e == d);
    }SECTION("Move assignment operator") {
        {
            DSString e = "Bonjour le Monde";
            d = std::move(e);
        }
        REQUIRE(d == "Bonjour le Monde");
    }
}