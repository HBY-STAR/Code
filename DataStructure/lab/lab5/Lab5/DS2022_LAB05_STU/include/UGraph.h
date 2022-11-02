//
// Created by HuaJuan on 2022/10/30.
//

#ifndef DS2022_LAB05_STU_UGRAPH_H
#define DS2022_LAB05_STU_UGRAPH_H

#include <vector>
#include <unordered_set>

class UGraph {
public:
    explicit UGraph(int nodeCnt);

public:
    [[nodiscard]] int nodeCnt() const;

    void addEdge(int x, int y);

    [[nodiscard]] bool isAdjacent(int x, int y) const;

    [[nodiscard]] std::vector<int> adjacentNodes(int x) const;

    [[nodiscard]] std::vector<int> bfs(int start) const;

    [[nodiscard]] std::vector<int> dfs(int start) const;
};

#endif //DS2022_LAB05_STU_UGRAPH_H
