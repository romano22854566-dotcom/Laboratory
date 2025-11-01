#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <cstddef>

class StringUtils {
public:
    static size_t stringLength(const char* str);
    static void stringCopy(char* dest,const char* src);
    static int stringCompare(const char* str1,const char* str2);
    static char* stringDuplicate(const char* src);
};

#endif