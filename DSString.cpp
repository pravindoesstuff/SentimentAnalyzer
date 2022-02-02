//
// Created by mark on 6/2/2021.
//

#include "DSString.h"

using std::unique_ptr;

DSString::DSString(size_t alloc_size) : str(new char[alloc_size + 1]) { str[alloc_size] = '\0'; }

DSString::DSString() : DSString("") {}

DSString::DSString(const char *str) : DSString(strlen(str) + 1) {
    strcpy(this->str, str);
}

DSString::DSString(const DSString &ds_string) : DSString(ds_string.str) {}

DSString::~DSString() {
    delete[] this->str;
}

DSString &DSString::operator=(const char *str) {
    *this = DSString(str);
    return *this;
}

DSString &DSString::operator=(const DSString &ds_string) {
    if (this != &ds_string) {
        this->str = new char[ds_string.getLength() + 1];
        strcpy(this->str, ds_string.str);
    }
    return *this;
}

DSString DSString::operator+(const DSString &ds_string) {
    DSString complete_ds_string(this->getLength() + ds_string.getLength());
    strcpy(complete_ds_string.str, this->str);
    strcat(complete_ds_string.str, ds_string.str);
    return complete_ds_string;
}

bool DSString::operator==(const char *str) const {
    return !strcmp(this->str, str);
}

bool DSString::operator==(const DSString &ds_string) const {
    return *this == ds_string.str;
}

bool DSString::operator>(const DSString &ds_string) const {
    return *this > ds_string.str;
}

bool DSString::operator>(const char *str) const {
    return strcmp(this->str, str) > 0;
}


DSString DSString::cleanPunctuation() const {
    size_t cleaned_str_len = 0;
    for (char *c = this->str; *c != '\0'; ++c) {
        if (!ispunct(*c)) ++cleaned_str_len;
    }
    DSString cleaned_str(cleaned_str_len);
    char *cleaned_str_ptr = cleaned_str.str;
    for (char *c = this->str; *c != '\0'; ++c) {
        if (!ispunct(*c)) *cleaned_str_ptr++ = (char) tolower(*c);
    }
    return {cleaned_str};
}

size_t DSString::find(char c) {
    return (char *) strchr(this->str, c) - this->str;
}

size_t DSString::getLength() const {
    return strlen(this->str);
}

char &DSString::operator[](const size_t index) {
    return this->str[index];
}

DSString DSString::substring(size_t start, size_t numChars) const {
    DSString ds_string(numChars);
    strncpy(ds_string.str, this->str + start, numChars);
    return ds_string;
}

char *DSString::c_str() const {
    return this->str;
}

// Referenced from: https://www.cplusplus.com/reference/ostream/ostream/write/
std::ostream &operator<<(std::ostream &os, const DSString &ds_string) {
    return os << ds_string.str;
}

unsigned int DSString::as_uint() {
    unsigned int result = 0;
    for (char *c = this->str; *c != '\0'; ++c) {
        result *= 10;
        result += *c - '0';
    }
    return result;
}
