//
// Created by mark on 6/2/2021.
//

#include "DSString.h"

DSString::DSString() {
    this->str = new char[0];
    this->length = 0;
}

DSString::DSString(const char *str) {
    this->length = 0;
    while (str[length++] != '\0'); //Adjust this->length to the size of str
    this->str = new char[length];
    for (int i = 0; i < length; ++i) this->str[i] = str[i];
}

DSString::DSString(const DSString &dsString) {
    this->length = dsString.length;
    this->str = new char[this->length];
    for (int i = 0; i < length; ++i) this->str[i] = dsString.str[i];
}

DSString::~DSString() {
    delete this->str;
}
