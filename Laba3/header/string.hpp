#pragma once
#include <cstddef>

class String {
private:
    char* data{nullptr};
    std::size_t length{0};

public:
    String() = default;
    explicit String(const char* s);
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    const char* cStr() const { return data ? data : ""; }
    std::size_t size() const { return length; }
};
