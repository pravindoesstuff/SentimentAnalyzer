//
// Created by mark on 6/2/2021.
//

#include "DSString.h"

DSString::DSString() {
    this->str = new char[0];
    this->length = 0;
}

DSString::DSString(const char *str) {
    this->length = strlen(str);
    this->str = new char[length];
    strcpy(this->str, str);
}

DSString::DSString(const DSString &dsString) {
    this->length = dsString.length;
    this->str = new char[this->length];
    strcpy(this->str, dsString.str);
}

DSString::~DSString() {
    delete[] this->str;
}

DSString &DSString::operator=(const char *str) {
    delete[] this->str;
    *this = DSString(str);
    return *this;
}

DSString &DSString::operator=(const DSString &dsString) {
    if (this == &dsString) return *this;
    delete[] this->str;
    *this = DSString(dsString);
    return *this;
}
