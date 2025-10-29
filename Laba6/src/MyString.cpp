#include "MyString.hpp"
#include <cstring>

void MyString::allocateAndCopy(const char* src,std::size_t len) {
    data = new char[len + 1];
    std::memcpy(data,src,len);
    data[len] = '\0';
    length = len;
}

MyString::MyString(): data(new char[1]{'\0'}) {}

MyString::MyString(const char* str) {
    if (!str) {
        data = new char[1]{'\0'};
        return;
    }
    const std::size_t len = std::strlen(str);
    if (len > MAX_LENGTH) {
        throw StringTooLongException("Ошибка: строка длиннее 10 символов.");
    }
    allocateAndCopy(str,len);
}

MyString::MyString(const MyString& other) {
    allocateAndCopy(other.data,other.length);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        auto newData = new char[other.length + 1];
        std::memcpy(newData,other.data,other.length);
        newData[other.length] = '\0';
        delete[] data;
        data = newData;
        length = other.length;
    }
    return *this;
}

MyString::~MyString() {
    delete[] data;
    data = nullptr;
    length = 0;
}

const char* MyString::c_str() const {
    return data;
}

std::size_t MyString::size() const {
    return length;
}

MyString operator+(const MyString& lhs,const MyString& rhs) {
    const std::size_t newLen = lhs.length + rhs.length;
    if (newLen > MyString::max_length()) {
        throw ConcatTooLongException("Ошибка: результат объединения длиннее 10 символов.");
    }
    auto buffer = new char[newLen + 1];
    std::memcpy(buffer,lhs.data,lhs.length);
    std::memcpy(buffer + lhs.length,rhs.data,rhs.length);
    buffer[newLen] = '\0';
    MyString result(buffer);
    delete[] buffer;
    return result;
}

std::size_t MyString::max_length() {
    return MAX_LENGTH;
}
