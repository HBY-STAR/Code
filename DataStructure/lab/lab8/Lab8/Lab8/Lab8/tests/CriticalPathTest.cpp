#include "gtest/gtest.h"
#include "CriticalPath.cpp"

class CriticalPathTest : public ::testing::Test {

};

TEST_F(CriticalPathTest, case01Topological) {
    vector<Edge> edges = vector<Edge>();
    edges.emplace_back(0, 3, 4, 4);
    edges.emplace_back(1, 2, 4, 2);
    edges.emplace_back(2, 2, 5, 3);
    edges.emplace_back(3, 4, 0, 2);
    edges.emplace_back(4, 1, 2, 3);
    edges.emplace_back(5, 3, 0, 3);
    edges.emplace_back(6, 1, 3, 2);
    edges.emplace_back(7, 5, 0, 1);

    CriticalPath graph = CriticalPath(edges, 6);
    auto result = graph.topologicalSort();

    ASSERT_EQ(1, result[0].getStart());
    ASSERT_EQ(0, result[result.size() - 1].getEnd());
}

TEST_F(CriticalPathTest, case02NodeEarly) {
    vector<Edge> edges = vector<Edge>();
    edges.emplace_back(0, 3, 4, 4);
    edges.emplace_back(1, 2, 4, 2);
    edges.emplace_back(2, 2, 5, 3);
    edges.emplace_back(3, 4, 0, 2);
    edges.emplace_back(4, 1, 2, 3);
    edges.emplace_back(5, 3, 0, 3);
    edges.emplace_back(6, 1, 3, 2);
    edges.emplace_back(7, 5, 0, 1);

    CriticalPath graph = CriticalPath(edges, 6);
    graph.topologicalSort();
    auto result = graph.nodesEarliestTime();

    ASSERT_EQ(6, result.size());
    ASSERT_EQ(8, result[0]);
    ASSERT_EQ(0, result[1]);
    ASSERT_EQ(3, result[2]);
    ASSERT_EQ(2, result[3]);
    ASSERT_EQ(6, result[4]);
    ASSERT_EQ(6, result[5]);
}

TEST_F(CriticalPathTest, case03NodeLate) {
    vector<Edge> edges = vector<Edge>();
    edges.emplace_back(0, 3, 4, 4);
    edges.emplace_back(1, 2, 4, 2);
    edges.emplace_back(2, 2, 5, 3);
    edges.emplace_back(3, 4, 0, 2);
    edges.emplace_back(4, 1, 2, 3);
    edges.emplace_back(5, 3, 0, 3);
    edges.emplace_back(6, 1, 3, 2);
    edges.emplace_back(7, 5, 0, 1);

    CriticalPath graph = CriticalPath(edges, 6);
    graph.topologicalSort();
    auto result = graph.nodesLatestTime();

    ASSERT_EQ(6, result.size());
    ASSERT_EQ(8, result[0]);
    ASSERT_EQ(0, result[1]);
    ASSERT_EQ(4, result[2]);
    ASSERT_EQ(2, result[3]);
    ASSERT_EQ(6, result[4]);
    ASSERT_EQ(7, result[5]);
}

TEST_F(CriticalPathTest, case04EdgeEarly) {
    vector<Edge> edges = vector<Edge>();
    edges.emplace_back(0, 3, 4, 4);
    edges.emplace_back(1, 2, 4, 2);
    edges.emplace_back(2, 2, 5, 3);
    edges.emplace_back(3, 4, 0, 2);
    edges.emplace_back(4, 1, 2, 3);
    edges.emplace_back(5, 3, 0, 3);
    edges.emplace_back(6, 1, 3, 2);
    edges.emplace_back(7, 5, 0, 1);

    CriticalPath graph = CriticalPath(edges, 6);
    graph.topologicalSort();
    auto result = graph.edgesEarliestTime();

    ASSERT_EQ(8, result.size());
    ASSERT_EQ(2, result[0]);
    ASSERT_EQ(3, result[1]);
    ASSERT_EQ(3, result[2]);
    ASSERT_EQ(6, result[3]);
    ASSERT_EQ(0, result[4]);
    ASSERT_EQ(2, result[5]);
    ASSERT_EQ(0, result[6]);
    ASSERT_EQ(6, result[7]);
}

TEST_F(CriticalPathTest, case05EdgeLate) {
    vector<Edge> edges = vector<Edge>();
    edges.emplace_back(0, 3, 4, 4);
    edges.emplace_back(1, 2, 4, 2);
    edges.emplace_back(2, 2, 5, 3);
    edges.emplace_back(3, 4, 0, 2);
    edges.emplace_back(4, 1, 2, 3);
    edges.emplace_back(5, 3, 0, 3);
    edges.emplace_back(6, 1, 3, 2);
    edges.emplace_back(7, 5, 0, 1);

    CriticalPath graph = CriticalPath(edges, 6);
    graph.topologicalSort();
    auto result = graph.edgesLatestTime();

    ASSERT_EQ(8, result.size());
    ASSERT_EQ(2, result[0]);
    ASSERT_EQ(4, result[1]);
    ASSERT_EQ(4, result[2]);
    ASSERT_EQ(6, result[3]);
    ASSERT_EQ(1, result[4]);
    ASSERT_EQ(5, result[5]);
    ASSERT_EQ(0, result[6]);
    ASSERT_EQ(7, result[7]);
}

TEST_F(CriticalPathTest, case06TimeDifference) {
    vector<Edge> edges = vector<Edge>();
    edges.emplace_back(0, 3, 4, 4);
    edges.emplace_back(1, 2, 4, 2);
    edges.emplace_back(2, 2, 5, 3);
    edges.emplace_back(3, 4, 0, 2);
    edges.emplace_back(4, 1, 2, 3);
    edges.emplace_back(5, 3, 0, 3);
    edges.emplace_back(6, 1, 3, 2);
    edges.emplace_back(7, 5, 0, 1);

    CriticalPath graph = CriticalPath(edges, 6);
    graph.topologicalSort();
    auto result = graph.timeDifference();

    ASSERT_EQ(8, result.size());
    ASSERT_EQ(0, result[0]);
    ASSERT_EQ(1, result[1]);
    ASSERT_EQ(1, result[2]);
    ASSERT_EQ(0, result[3]);
    ASSERT_EQ(1, result[4]);
    ASSERT_EQ(3, result[5]);
    ASSERT_EQ(0, result[6]);
    ASSERT_EQ(1, result[7]);
}

TEST_F(CriticalPathTest, case07CriticalPath) {
    vector<Edge> edges = vector<Edge>();
    edges.emplace_back(0, 3, 4, 4);
    edges.emplace_back(1, 2, 4, 2);
    edges.emplace_back(2, 2, 5, 3);
    edges.emplace_back(3, 4, 0, 2);
    edges.emplace_back(4, 1, 2, 3);
    edges.emplace_back(5, 3, 0, 3);
    edges.emplace_back(6, 1, 3, 2);
    edges.emplace_back(7, 5, 0, 1);

    CriticalPath graph = CriticalPath(edges, 6);
    graph.topologicalSort();
    auto result = graph.getCriticalPath();

    ASSERT_EQ(3, result.size());
    ASSERT_EQ(6, result[0].getId());
    ASSERT_EQ(0, result[1].getId());
    ASSERT_EQ(3, result[2].getId());
}