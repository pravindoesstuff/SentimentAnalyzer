//
// Created by Mark Fontenot on 6/2/2021.
//

#ifndef PA01_SENTIMENT_DSSTRING_H
#define PA01_SENTIMENT_DSSTRING_H

#include <iostream>
#include <cstring>

class DSString {

private:


    char *str;
    size_t length;
    /**
     *  You will need to add some private data members here.
     *  This is up to your discretion.  However, we **strongly**
     *  encourage you to implement your string class as a wrapper
     *  for typical null-terminated c-strings.  In doing this, you
     *  may use c-string functions in the methods in this class such
     *  as:
     *    * strlen(...)
     *    * strcpy(...)
     *    * strcmp(...)
     *    * strncpy(...)
     *    * strcat(...)
     *    * strncat(...)
     *
     *    A quick google search will return plenty of references on
     *    the c-string functions.
     **/

    /// Private constructor to unsafely char[] pointers into DSString
    DSString(const char *str, size_t length);

public:

    /**
     * Constructors and destructor
     *
     * Make sure you do proper memory management.
     **/
    DSString();

    DSString(const char *);

    DSString(const DSString &);

    ~DSString();

    /**
     * Overloaded Assignment Operators
     */
    DSString &operator=(const char *);

    DSString &operator=(const DSString &);

    /**
     * Overloaded non-modifying string concat
     * @return
     */
    DSString operator+(const DSString &);

    /**
     * Standard relational operators.  Feel free to add additional.
     *
     * Note that for each operator, there are two overloaded versions:
     *    one that takes a DSString object
     *    one that takes a null-terminated c-string
     *
     **/

    bool operator==(const char *);

    bool operator==(const DSString &);

    bool operator>(const DSString &);

    bool operator>(const char *);

    /**
     * Subscript operator to access a particular character of a DSString object
     * @return the character requested by reference
     */
    char &operator[](size_t);

    /**
     * getLength() returns the number (count) of characters in the string.
     **/
    [[nodiscard]] size_t getLength() const;

    /**
     * cleanPunctuation() Returns a DSString with all punctuation removed
     **/
    [[nodiscard]] DSString cleanPunctuation() const;

    /**
     * The substring method returns a DSString object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    [[nodiscard]] DSString substring(size_t start, size_t numChars) const;

    [[nodiscard]] size_t find(char c);

    /**
     * the c_str function returns a null-terminated c-string holding the
     * contents of this object.
     **/
    [[nodiscard]] char *c_str();

    [[nodiscard]] uint as_uint();

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
    friend std::ostream &operator<<(std::ostream &, const DSString &);

    //You are free to add more functionality to the class.  For example,
    //you may want to add a find(...) function that will search for a
    //string within a string.  (just an example)
    //
    //Further - you will be able to update and modify this class as the
    //semester progresses.

};


#endif //PA01_SENTIMENT_DSSTRING_H
