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
    return (double) weight / (double) rankings;
}