#include <cstddef>

#pragma once

class customString {
    private:
        typedef char* arrayString;
    public:
        customString();
        customString(const customString & original);
        customString(char str[], size_t size);
        ~customString();
        customString& operator=(const customString & rhs);
        char operator[](int index);
        arrayString getString();
        void setString(char str[], size_t size);
        void append(char newChar);
        void concatenate(const arrayString& b);
        void remove(int index, int numRemove);
    private:
        void copyCharacters(arrayString& dest, const arrayString& src, int length);
        arrayString _head;
        int length(const arrayString& s);
        void deleteString(arrayString head);
        arrayString copiedString(const arrayString& original);
};
