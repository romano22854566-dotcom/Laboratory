#include "string.hpp"
#include <cstring>

String::String(): data(nullptr),length(0) {}

String::String(const char* s): data(nullptr),length(0) {
    if (s) {
        length = std::strlen(s);
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
