#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <string>

class StringUtils {
public:
    static size_t stringLength(const std::string& str) { return str.size(); }
    static void stringCopy(std::string& dest,const std::string& src) { dest = src; }
    static int stringCompare(const std::string& str1,const std::string& str2) { return str1.compare(str2); }
    static std::string stringDuplicate(const std::string& src) { return src; }
};

#endif
