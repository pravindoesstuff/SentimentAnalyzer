#include <iostream>
#include "DSString.h"
#include "FrequencyCollector.h"
#include "Tweet.h"

//#define CATCH_CONFIG_RUNNER

//#include <catch2/catch.hpp>

using namespace std;

int main(int argc, char **argv) {
    DSString tweet_string = "2002781955,Tue Jun 02 05:08:46 PDT 2009,NO_QUERY,S810uk,Sitting in the office forced to look at the sunshine from my window  At least I have a window to stare through. Only 2 wks to my run :-&amp;";
    DSString tw = tweet_string;
    Tweet tweet(tweet_string);
}
