#pragma once
#include <cstddef>

class String {
private:
    char* data_;
    std::size_t size_;
    void allocateAndCopy(const char* s);

public:
    String();
    String(const char* s);
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    void set(const char* s);
    const char* cStr() const;
    std::size_t size() const;
    bool empty() const;
};
