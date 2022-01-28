//
// Created by pravin on 1/27/22.
//

#include "Bias.h"

void Bias::add_positive() {
    ++positive;
}

void Bias::add_negative() {
    ++negative;
}

double Bias::ratio() const {
    return (double) positive / (double) negative;
}