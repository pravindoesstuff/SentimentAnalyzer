//
// Created by pravin on 1/28/22.
//

#include "Tweet.h"

Tweet::Tweet(bool has_sentiment, DSString data_line) {
    if (has_sentiment) {
        DSString id_str = data_line.substring(2, 10);
        this->is_positive = data_line[0] == '4';
        this->id = id_str.as_uint();
        DSString display_name_and_body = data_line.substring(51, data_line.getLength() - 46);
        this->tweet_body = display_name_and_body.substring(display_name_and_body.find(',') + 1,
                                                           data_line.getLength() - 6);
    } else {
        DSString id_str = data_line.substring(0, 10);
        this->id = id_str.as_uint();
        DSString display_name_and_body = data_line.substring(49, data_line.getLength() - 44);
        this->tweet_body = display_name_and_body.substring(display_name_and_body.find(',') + 1,
                                                           data_line.getLength() - 6);
    }
}
