#include "gtest/gtest.h"
#include "UGraph.h"
#include "LegalDFSBFSChecker.h"

class UGraphTest : public ::testing::Test {
protected:
    void SetUp() override {
        UGraph graph1(1);

        UGraph graph2(3);
        graph2.addEdge(0, 1);
        graph2.addEdge(0, 2);
        graph2.addEdge(1, 2);

        UGraph graph3(6);
        graph3.addEdge(2, 4);
        graph3.addEdge(1, 2);
        graph3.addEdge(2, 2);
        graph3.addEdge(1, 4);
        graph3.addEdge(2, 3);
        graph3.addEdge(0, 1);
        graph3.addEdge(0, 4);
        graph3.addEdge(3, 2);

        UGraph graph4(10);
        graph4.addEdge(9, 7);
        graph4.addEdge(6, 5);
        graph4.addEdge(8, 0);
        graph4.addEdge(2, 8);
        graph4.addEdge(6, 6);
        graph4.addEdge(7, 5);
        graph4.addEdge(7, 4);
        graph4.addEdge(1, 9);
        graph4.addEdge(4, 6);
        graph4.addEdge(6, 4);
        graph4.addEdge(3, 7);
        graph4.addEdge(0, 4);
        graph4.addEdge(1, 8);
        graph4.addEdge(2, 4);
        graph4.addEdge(3, 0);
        graph4.addEdge(0, 5);
        graph4.addEdge(1, 2);
        graph4.addEdge(7, 6);
        graph4.addEdge(3, 1);
        graph4.addEdge(1, 7);
        graph4.addEdge(5, 2);
        graph4.addEdge(2, 5);
        graph4.addEdge(0, 8);
        graph4.addEdge(6, 1);
        graph4.addEdge(2, 1);
        graph4.addEdge(9, 6);
        graph4.addEdge(8, 5);

        graphs.push_back(graph1);
        graphs.push_back(graph2);
        graphs.push_back(graph3);
        graphs.push_back(graph4);
    }

    std::vector<UGraph> graphs;
    LegalDFSBFSChecker checker;
};

std::string toString(const std::vector<int> &v) {
    std::string res;
    for (int i = 0; i < v.size(); i++) {
        res += std::to_string(v[i]);
        if (i + 1 < v.size()) {
            res += " ";
        }
    }
    return res;
}


TEST_F(UGraphTest, bfsTest) {
    for (int i = 0; i < graphs.size(); i++) {
        auto bfsSequence = graphs[i].bfs(0);
        ASSERT_TRUE(checker.checkBFS(graphs[i], 0, bfsSequence))
                                    << "BFS test on graph " << i << " failed!" << std::endl
                                    << " Your BFS sequence is " << toString(bfsSequence);
    }
}


TEST_F(UGraphTest, dfsTest) {
    for (int i = 0; i < graphs.size(); i++) {
        auto dfsSequence = graphs[i].dfs(0);
        ASSERT_TRUE(checker.checkDFS(graphs[i], 0, dfsSequence))
                                    << "DFS test on graph " << i << " failed!" << std::endl
                                    << " Your BFS sequence is " << toString(dfsSequence);
    }
}