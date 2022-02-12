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

TEST_CASE("String concat functions correctly") {
    SECTION("concat 3 strings") {
        DSString dsString;
        { //new dsString should hold "Hello World" even when the original DSStrings are out of scope
            DSString a = "Hello";
            DSString b = " ";
            DSString c = "World";
            dsString = a + b + c;
        }
        REQUIRE(dsString == "Hello World");
    }
}

TEST_CASE("remove_adjacent_letters test") {
    SECTION("No adjustments needed") {
        DSString d = "lol i was there";
        d.remove_adjacent_letters();
        REQUIRE(d == "lol i was there");
    }SECTION("adjustments needed") {
        DSString d = "lollllll whaaaat arrree yooooouuuu doooiinnnnggggg";
        d.remove_adjacent_letters();
        REQUIRE(d == "lol what are you doing");
    }
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