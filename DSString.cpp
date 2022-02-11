//
// Created by mark on 6/2/2021.
//

#include "DSString.h"

DSString::DSString(const size_t &alloc_size) : str(new char[alloc_size + 1]) { str[alloc_size] = '\0'; }

DSString::DSString() : DSString("") {}

DSString::DSString(const char *str) : DSString(strlen(str)) {
    strcpy(this->str, str);
}

DSString::DSString(const DSString &ds_string) : DSString(ds_string.str) {}

// Referenced from: https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp
DSString::DSString(DSString &&ds_string) noexcept: str(nullptr) {
    *this = std::move(ds_string);
}

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

// Referenced from: https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp
DSString &DSString::operator=(DSString &&ds_string) noexcept {
    if (this != &ds_string) {
        delete[] this->str;
        this->str = ds_string.str;
        ds_string.str = nullptr;
    }
    return *this;
}

DSString DSString::operator+(const DSString &ds_string) const {
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

void DSString::sanitize() {
    for (char *c = this->str; *c != '\0'; ++c) {
        *c = isalpha(*c) ? (char) tolower(*c) : ' ';
    }
}

void DSString::remove_adjacent_letters() {
    char *current_ptr = this->str;
    char previous_char = '\0';
    for (char *c = this->str; *c != '\0'; ++c) {
        if (*c != previous_char) {
            previous_char = *c;
            *current_ptr = *c;
            ++current_ptr;
        }
    }
    *current_ptr = '\0';
}

size_t DSString::find(const char &c) const {
    return strchr(this->str, c) - this->str;
}

size_t DSString::getLength() const {
    return strlen(this->str);
}

char &DSString::operator[](const size_t &index) {
    return this->str[index];
}

DSString DSString::substring(const size_t &start, const size_t &numChars) const {
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

unsigned int DSString::as_uint() const {
    unsigned int result = 0;
    for (char *c = this->str; *c != '\0'; ++c) {
        result *= 10;
        result += *c - '0';
    }
    return result;
}
