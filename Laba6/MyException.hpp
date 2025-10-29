#pragma once
#include <string>

class StringTooLongException {
public:
    explicit StringTooLongException(const std::string& msg);
    const char* what() const noexcept;

private:
    std::string message;
};

class ConcatTooLongException {
public:
    explicit ConcatTooLongException(const std::string& msg);
    const char* what() const noexcept;

private:
    std::string message;
};
