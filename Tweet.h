//
// Created by pravin on 1/28/22.
//

#ifndef PA01_SENTIMENT_TWEET_H
#define PA01_SENTIMENT_TWEET_H


#include "DSString.h"

class Tweet {
public:
    uint32_t id;
    DSString tweet_body;
    bool is_positive;
public:
    explicit Tweet(DSString data_line);
};


#endif //PA01_SENTIMENT_TWEET_H
