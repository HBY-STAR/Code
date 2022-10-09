//
// Created by HuaJuan on 2022/10/7.
//

#ifndef DS2022_LAB03_TA_KMP_H
#define DS2022_LAB03_TA_KMP_H

#include <string>
#include <vector>

class KMP {
public:
    static int strStr(const std::string &haystack, const std::string &needle);

private:
    static std::vector<int> getNextArr(const std::string &needle);
};

#endif //DS2022_LAB03_TA_KMP_H
