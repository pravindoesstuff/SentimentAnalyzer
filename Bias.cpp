//
// Created by pravin on 1/27/22.
//

#include "Bias.h"

void Bias::add_positive() {
    weight += 1;
    ++rankings;
}

void Bias::add_negative() {
    weight += 0;
    ++rankings;
}

double Bias::average() const {
    double average = (double) weight / (double) rankings;
    // Uncertain predictions (under a threshold) should return 0.5, which will cause them to be culled
    // This will greatly help with removing uncommon words that can tip averages
    if (rankings < 7) return 0.5; // 7 Was found to be a good value based on the default 20k training set
    else return average;
}