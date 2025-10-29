#pragma once
#include <cstddef>
#include "MyException.hpp"

class MyString {
private:
    char* data;
    std::size_t length;
    static const std::size_t MAX_LENGTH = 10; 
    void allocateAndCopy(const char* src,std::size_t len);

public:
    MyString();
    explicit MyString(const char* str);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    const char* c_str() const;
    std::size_t size() const;

    MyString operator+(const MyString& other) const;

    static std::size_t max_length();
};
