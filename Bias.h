//
// Created by pravin on 1/27/22.
//

#ifndef PA01_SENTIMENT_BIAS_H
#define PA01_SENTIMENT_BIAS_H


class Bias {
private:
    unsigned long weight = 0, rankings = 0;
public:
    void add_negative();

    void add_positive();
    /// Returns the leanings of the bias, 0 leaning negative and 1 leaning positive
    [[nodiscard]] double average() const;
};


#endif //PA01_SENTIMENT_BIAS_H
