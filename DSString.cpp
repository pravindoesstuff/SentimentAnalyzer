//
// Created by mark on 6/2/2021.
//

#include "DSString.h"

DSString::DSString() {
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
    *this = DSString(str);
    return *this;
}

DSString &DSString::operator=(const DSString &ds_string) {
    if (this == &ds_string) return *this;
    delete[] this->str; // TODO Note: A double deletion occurs when &DSString::operator=(const char *str) is called
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

bool DSString::operator==(const char *str) {
    return !memcmp(this->str, str, this->length);
}

bool DSString::operator==(const DSString &ds_string) {
    return *this > ds_string.str;
}

bool DSString::operator>(const DSString &ds_string) {
    return *this > ds_string.str;
}

bool DSString::operator>(const char *str) {
    return memcmp(this->str, str, this->length) > 0;
}

int DSString::getLength() {
    return (int) this->length;
}

char &DSString::operator[](const int index) {
    return this->str[index];
}

DSString DSString::substring(int start, int numChars) {
    DSString sub_ds_string;
    sub_ds_string.length = numChars;
    sub_ds_string.str = new char[numChars];
    memcpy(sub_ds_string.str, this->str + start, numChars);
    return sub_ds_string;
}

// This leaks the char[] and should be avoided
char *DSString::c_str() {
    return this->str;
}

// Referenced from: https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes
std::ostream &operator<<(std::ostream &os, const DSString &ds_string) {
    return os << ds_string.str;
}
