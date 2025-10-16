#include "string.hpp"
#include <cstring>

static void safeStrCopy(char* dest,const char* src,std::size_t maxLen) {
    if (!dest || maxLen == 0) return;
    if (!src) {
        dest[0] = '\0';
        return;
    }
    std::size_t i = 0;
    for (; i < maxLen - 1 && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

void String::allocateAndCopy(const char* s) {
    if (!s) {
        data_ = new char[1];
        data_[0] = '\0';
        size_ = 0;
        return;
    }
    size_ = std::strlen(s);
    data_ = new char[size_ + 1];
    safeStrCopy(data_,s,size_ + 1);
}

String::String(): data_(nullptr),size_(0) { allocateAndCopy(""); }
String::String(const char* s): data_(nullptr),size_(0) { allocateAndCopy(s); }
String::String(const String& other): data_(nullptr),size_(0) { allocateAndCopy(other.data_); }

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data_;
        allocateAndCopy(other.data_);
    }
    return *this;
}

String::~String() { delete[] data_; }

void String::set(const char* s) {
    delete[] data_;
    allocateAndCopy(s);
}

const char* String::cStr() const { return data_; }
std::size_t String::size() const { return size_; }
bool String::empty() const { return size_ == 0; }
