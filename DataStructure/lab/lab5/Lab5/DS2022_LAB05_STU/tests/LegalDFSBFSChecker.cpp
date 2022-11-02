//
// Created by HuaJuan on 2022/10/30.
//

#include "LegalDFSBFSChecker.h"
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;


bool hasAdjacentUnvisitedNode(const UGraph &uGraph, int curNode, const vector<bool> &visited) {
    auto adjNodes = uGraph.adjacentNodes(curNode);
    return std::any_of(adjNodes.begin(), adjNodes.end(), [&visited](int n) { return !visited[n]; });
}

bool LegalDFSBFSChecker::checkDFS(const UGraph &uGraph, int start, const std::vector<int> &dfsSequence) {
    if (dfsSequence.front() != start) {
        return false;
    }
    vector<bool> visited(uGraph.nodeCnt(), false);

    if (dfsSequence.size() == 1 && hasAdjacentUnvisitedNode(uGraph, start, visited)) {
        return false;
    }


    for (int i = 0; i + 1 < dfsSequence.size(); i++) {
        int curNode = dfsSequence[i];
        visited[curNode] = true;
        int nextNode = dfsSequence[i + 1];

        if (visited[nextNode]) {
            // 尝试访问已经访问过的节点
            return false;
        } else if (hasAdjacentUnvisitedNode(uGraph, curNode, visited)) {
            if (!uGraph.isAdjacent(curNode, nextNode)) {
                return false;
            }
        } else {
            int j = i - 1;
            while (j >= 0) {
                int prevNode = dfsSequence[j];
                if (hasAdjacentUnvisitedNode(uGraph, prevNode, visited)) {
                    if (uGraph.isAdjacent(prevNode, nextNode)) {
                        break;
                    } else {
                        return false;
                    }
                }
                j--;
            }
            if (j == -1) {
                return false;
            }
        }
    }
    return true;
}

bool LegalDFSBFSChecker::checkBFS(const UGraph &uGraph, int start, const std::vector<int> &bfsSequence) {
    if (bfsSequence.front() != start) {
        return false;
    }

    vector<bool> visited(uGraph.nodeCnt(), false);
    queue<int> q;
    unordered_map<int, int> nodeToLevel;
    vector<int> myBFSSequence;

    visited[start] = true;
    q.push(start);

    int curLevel = 0;

    while (!q.empty()) {
        size_t sz = q.size();

        for (size_t i = 0; i < sz; i++) {

            int curNode = q.front();
            q.pop();
            nodeToLevel[curNode] = curLevel;
            myBFSSequence.push_back(curNode);

            for (auto adjNode: uGraph.adjacentNodes(curNode)) {
                if (!visited[adjNode]) {
                    q.push(adjNode);
                    visited[adjNode] = true;
                }
            }
        }
        curLevel++;
    }


    std::fill(visited.begin(), visited.end(), false);

    for (int i = 0; i + 1 < bfsSequence.size(); ++i) {
        int curNode = bfsSequence[i];
        int nextNode = bfsSequence[i + 1];
        visited[curNode] = true;
        if (visited[nextNode]) {
            return false;
        }
    }

    vector<int> mySequenceLevels;
    vector<int> sequenceLevels;

    for (auto &n: bfsSequence) {
        sequenceLevels.emplace_back(nodeToLevel[n]);
    }
    for (auto &n: myBFSSequence) {
        mySequenceLevels.emplace_back(nodeToLevel[n]);
    }

    return sequenceLevels == mySequenceLevels;
}
