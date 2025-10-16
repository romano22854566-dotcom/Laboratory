#pragma once
#include <cstddef>

class String {
private:
    char* data;
    std::size_t length;

public:
    String();
    explicit String(const char* s);
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    const char* cStr() const;
    std::size_t size() const;
};
