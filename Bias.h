//
// Created by pravin on 1/27/22.
//

#ifndef PA01_SENTIMENT_BIAS_H
#define PA01_SENTIMENT_BIAS_H


class Bias {
private:
    unsigned long positive, negative;
public:
    void add_negative();
    void add_positive();
    [[nodiscard]] double ratio() const;
};


#endif //PA01_SENTIMENT_BIAS_H
