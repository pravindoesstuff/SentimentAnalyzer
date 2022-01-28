//
// Created by mark on 6/2/2021.
//

#include "DSString.h"
#include <memory>

using std::unique_ptr;

DSString::DSString(const char *str, size_t length) : length(length) {
    this->str = new char[this->length];
    memcpy(this->str, str, this->length);
}

DSString::DSString() : DSString({}, 0) {}

DSString::DSString(const char *str) : DSString(str, strlen(str)) {}

DSString::DSString(const DSString &ds_string) : DSString(ds_string.str, ds_string.length) {}

DSString::~DSString() {
    delete[] this->str;
}

DSString &DSString::operator=(const char *str) {
    *this = DSString(str);
    return *this;
}

DSString &DSString::operator=(const DSString &ds_string) {
    if (this != &ds_string) *this = DSString(ds_string);
    return *this;
}

DSString DSString::operator+(const DSString &ds_string) {
    DSString complete_ds_string(this->str, this->length + ds_string.length);
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


DSString DSString::cleanPunctuation() const {
    size_t cleaned_str_len = 0;
    for (int i = 0; i < this->length; ++i) {
        if (!ispunct(this->str[i])) ++cleaned_str_len;
    }
    unique_ptr<char> cleaned_str(new char[cleaned_str_len]);
    char *cleaned_str_ptr = cleaned_str.get();
    for (int i = 0; i < this->length; ++i) {
        if (!ispunct(this->str[i])) *cleaned_str_ptr++ = this->str[i];
    }
    return {cleaned_str.get(), cleaned_str_len};
}

int DSString::getLength() const {
    return (int) this->length;
}

char &DSString::operator[](const int index) {
    return this->str[index];
}

DSString DSString::substring(int start, int numChars) const {
    return {this->str + start, (size_t) numChars};
}

// This leaks the char[] and should be avoided and currently does not guarantee null termination
char *DSString::c_str() {
    return this->str;
}

// Referenced from: https://www.cplusplus.com/reference/ostream/ostream/write/
std::ostream &operator<<(std::ostream &os, const DSString &ds_string) {
    return os.write(ds_string.str, (int) ds_string.length);
}
