#include "string.hpp"
#include <cstring>

String::String(const char* s) {
    if (s) {
        length = std::strlen(s);
        data = new char[length + 1];
        std::memcpy(data,s,length);
        data[length] = '\0';
    }
}

String::String(const String& other) {
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
