//
// Created by pravin on 1/28/22.
//

#include "Tweet.h"

Tweet::Tweet(bool has_sentiment, DSString data_line) {
    this->is_positive = data_line[0] == '4';
    int start = has_sentiment ? 2 : 0;
    this->id = data_line.substring(start, 10).as_uint();
    DSString display_name_and_body = data_line.substring(start + 49, data_line.getLength() - 44 + start);
    this->tweet_body = display_name_and_body.substring(display_name_and_body.find(',') + 1,
                                                       data_line.getLength() - 6);
}
