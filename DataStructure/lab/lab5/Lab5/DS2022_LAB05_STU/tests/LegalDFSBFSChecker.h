//
// Created by HuaJuan on 2022/10/30.
//

#ifndef DS2022_LAB05_STU_LEGALDFSBFSCHECKER_H
#define DS2022_LAB05_STU_LEGALDFSBFSCHECKER_H

#include <vector>
#include "UGraph.h"

class LegalDFSBFSChecker {
public:
    bool checkDFS(const UGraph &uGraph, int start, const std::vector<int> &dfsSequence);

    bool checkBFS(const UGraph &uGraph, int start, const std::vector<int> &bfsSequence);
};

#endif //DS2022_LAB05_STU_LEGALDFSBFSCHECKER_H
