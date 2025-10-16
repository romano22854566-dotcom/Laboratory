#include "string.hpp"
#include <cstring>


static std::size_t myStrLen(const char* s) {
    if (!s) return 0;
    std::size_t len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    return len;
}
String::String(): data(nullptr),length(0) {}
String::String(const char* s): data(nullptr),length(0) {
    if (s) {
        length = myStrLen(s); 
        data = new char[length + 1];
        std::memcpy(data,s,length);
        data[length] = '\0';
    }
}

String::String(const String& other): data(nullptr),length(0) {
    if (other.data) {
        length = other.length;
        data = new char[length + 1];
        std::memcpy(data,other.data,length);
        data[length] = '\0';
    }
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        std::memcpy(data,other.data,length);
        data[length] = '\0';
    }
    return *this;
}

String::~String() {
    delete[] data;
}

const char* String::cStr() const {
    return data ? data : "";
}

std::size_t String::size() const {
    return length;
}
