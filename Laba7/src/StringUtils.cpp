#include "StringUtils.hpp"

size_t StringUtils::stringLength(const char* str) {
    if (!str) {
        return 0;
    }

    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

void StringUtils::stringCopy(char* dest,const char* src) {
    if (!dest || !src) {
        return;
    }

    size_t i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int StringUtils::stringCompare(const char* str1,const char* str2) {
    if (!str1 || !str2) {
        if (!str1 && !str2) return 0;
        if (!str1) return -1;
        return 1;
    }

    size_t i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

char* StringUtils::stringDuplicate(const char* src) {
    if (!src) {
        return nullptr;
    }

    size_t length = stringLength(src);
    char* duplicate = new char[length + 1];
    stringCopy(duplicate,src);

    return duplicate;
}