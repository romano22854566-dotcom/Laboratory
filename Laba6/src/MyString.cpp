#include "MyString.hpp"
#include <cstring>

void MyString::allocateAndCopy(const char* src,std::size_t len) {
    data = new char[len + 1];
    std::memcpy(data,src,len);
    data[len] = '\0';
    length = len;
}

MyString::MyString(): data(nullptr),length(0) {
    data = new char[1];
    data[0] = '\0';
}

MyString::MyString(const char* str): data(nullptr),length(0) {
    if (!str) {
        data = new char[1];
        data[0] = '\0';
        return;
    }
    std::size_t len = std::strlen(str);
    if (len > MAX_LENGTH) {
        throw StringTooLongException("Ошибка строка длиннее 10 символов");
    }
    allocateAndCopy(str,len);
}

MyString::MyString(const MyString& other): data(nullptr),length(0) {
    allocateAndCopy(other.data,other.length);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        char* newData = new char[other.length + 1];
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
}

const char* MyString::c_str() const {
    return data;
}

std::size_t MyString::size() const {
    return length;
}

MyString MyString::operator+(const MyString& other) const {
    std::size_t newLen = length + other.length;
    if (newLen > MAX_LENGTH) {
        throw ConcatTooLongException("Ошибка Результат объединения длиннее 10 символов");
    }
    char* buffer = new char[newLen + 1];
    std::memcpy(buffer,data,length);
    std::memcpy(buffer + length,other.data,other.length);
    buffer[newLen] = '\0';
    MyString result(buffer);
    delete[] buffer;
    return result;
}

std::size_t MyString::max_length() {
    return MAX_LENGTH;
}
