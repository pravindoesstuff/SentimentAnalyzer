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
    memcpy(this->str, str, this->length);
}

DSString::DSString(const DSString &ds_string) {
    this->length = ds_string.length;
    this->str = new char[this->length];
    memcpy(this->str, ds_string.str, this->length);
}

DSString::~DSString() {
    delete[] this->str;
}

DSString &DSString::operator=(const char *str) {
    delete[] this->str;
    *this = DSString(str);
    return *this;
}

DSString &DSString::operator=(const DSString &ds_string) {
    if (this == &ds_string) return *this;
    delete[] this->str;
    *this = DSString(ds_string);
    return *this;
}

DSString DSString::operator+(const DSString &ds_string) {
    DSString complete_ds_string;
    complete_ds_string.length = this->length + ds_string.length;
    complete_ds_string.str = new char[complete_ds_string.length];
    memcpy(complete_ds_string.str, this->str, this->length);
    memcpy(complete_ds_string.str + this->length, ds_string.str, this->length + ds_string.length);
    return complete_ds_string;
}

// This leaks the char[] and should be avoided
char *DSString::c_str() {
    return this->str;
}
