#include "MyException.hpp"

StringTooLongException::StringTooLongException(const std::string& msg)
    : message(msg) {
}

const char* StringTooLongException::what() const noexcept {
    return message.c_str();
}

ConcatTooLongException::ConcatTooLongException(const std::string& msg)
    : message(msg) {
}

const char* ConcatTooLongException::what() const noexcept {
    return message.c_str();
}
