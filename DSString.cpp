//
// Created by mark on 6/2/2021.
//

#include "DSString.h"

DSString::DSString() {
    this->str = new char[0];
    this->length = 0;
}

DSString::DSString(char *str, size_t length) {
    this->length = length;
    this->str = new char[this->length];
    memcpy(this->str, str, this->length);
}

DSString::DSString(const char *str) {
    this->length = strlen(str);
    this->str = new char[this->length];
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
    this->length = strlen(str);
    this->str = new char[this->length];
    memcpy(this->str, str, this->length);
    return *this;
}

DSString &DSString::operator=(const DSString &ds_string) {
    if (this == &ds_string) return *this;
    delete[] this->str;
    this->length = ds_string.length;
    this->str = new char[this->length];
    memcpy(this->str, ds_string.str, this->length);
    return *this;
}

DSString DSString::operator+(const DSString &ds_string) {
    DSString complete_ds_string;
    delete[] complete_ds_string.str;
    complete_ds_string.length = this->length + ds_string.length;
    complete_ds_string.str = new char[complete_ds_string.length];
    memcpy(complete_ds_string.str, this->str, this->length);
    memcpy(complete_ds_string.str + this->length, ds_string.str, ds_string.length);
    return complete_ds_string;
}

bool DSString::operator==(const char *str) {
    return !memcmp(this->str, str, this->length);
}

bool DSString::operator==(const DSString &ds_string) {
    return *this == ds_string.str;
}

bool DSString::operator>(const DSString &ds_string) {
    return *this > ds_string.str;
}

bool DSString::operator>(const char *str) {
    return memcmp(this->str, str, this->length) > 0;
}


DSString DSString::cleanPunctuation() {
    size_t cleaned_str_len = 0;
    for (int i = 0; i < this->length; ++i) {
        if (!ispunct(this->str[i])) ++cleaned_str_len;
    }
    char cleaned_str[cleaned_str_len];
    char *cleaned_str_prt = cleaned_str;
    for (int i = 0; i < this->length; ++i) {
        if (!ispunct(this->str[i])) *cleaned_str_prt++ = this->str[i];
    }
    return {cleaned_str, cleaned_str_len};
}

int DSString::getLength() {
    return (int) this->length;
}

char &DSString::operator[](const int index) {
    return this->str[index];
}

DSString DSString::substring(int start, int numChars) {
    DSString sub_ds_string;
    delete[] sub_ds_string.str;
    sub_ds_string.length = numChars;
    sub_ds_string.str = new char[numChars];
    memcpy(sub_ds_string.str, this->str + start, numChars);
    return sub_ds_string;
}

// This leaks the char[] and should be avoided and currently does not guarantee null termination
char *DSString::c_str() {
    return this->str;
}

// Referenced from: https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes
std::ostream &operator<<(std::ostream &os, const DSString &ds_string) {
    return os.write(ds_string.str, (int) ds_string.length);
}
