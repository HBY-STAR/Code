#include "gtest/gtest.h"
#include "Kruskal.cpp"

class KruskalTest : public ::testing::Test {

};

TEST_F(KruskalTest, case01) {
    vector<Edge> edges = vector<Edge>();
    edges.emplace_back(0, 3, 10);
    edges.emplace_back(0, 1, 4);
    edges.emplace_back(1, 2, 5);
    edges.emplace_back(2, 3, 2);
    edges.emplace_back(0, 2, 6);
    edges.emplace_back(1, 3, 1);

    Kruskal graph = Kruskal(edges, 4);
    vector<Edge> mst = graph.findMST();

    ASSERT_EQ(1, mst[0].getV1());
    ASSERT_EQ(3, mst[0].getV2());
    ASSERT_EQ(2, mst[1].getV1());
    ASSERT_EQ(3, mst[1].getV2());
    ASSERT_EQ(0, mst[2].getV1());
    ASSERT_EQ(1, mst[2].getV2());

    ASSERT_EQ(3, mst.size());
    ASSERT_EQ(1, mst[0].getLen());
    ASSERT_EQ(2, mst[1].getLen());
    ASSERT_EQ(4, mst[2].getLen());
    ASSERT_EQ(7, graph.findTotalLength());
}

TEST_F(KruskalTest, case02) {
    vector<Edge> edges = vector<Edge>();
    edges.emplace_back(1, 0, 10);
    edges.emplace_back(1, 2, 2);
    edges.emplace_back(2, 3, 3);
    edges.emplace_back(3, 4, 6);
    edges.emplace_back(1, 3, 5);
    edges.emplace_back(0, 4, 4);
    edges.emplace_back(1, 0, 1);

    Kruskal graph = Kruskal(edges, 5);
    vector<Edge> mst = graph.findMST();

    ASSERT_EQ(4, mst.size());
    ASSERT_EQ(1, mst[0].getLen());
    ASSERT_EQ(2, mst[1].getLen());
    ASSERT_EQ(3, mst[2].getLen());
    ASSERT_EQ(4, mst[3].getLen());
    ASSERT_EQ(10, graph.findTotalLength());
}

TEST_F(KruskalTest, case03) {
    vector<Edge> edges = vector<Edge>();
    edges.emplace_back(6, 5, 10);
    edges.emplace_back(6, 4, 9);
    edges.emplace_back(6, 3, 8);
    edges.emplace_back(6, 2, 7);
    edges.emplace_back(6, 1, 6);
    edges.emplace_back(6, 0, 5);
    edges.emplace_back(0, 5, 9);
    edges.emplace_back(0, 1, 8);
    edges.emplace_back(1, 2, 6);
    edges.emplace_back(2, 3, 7);
    edges.emplace_back(3, 4, 11);
    edges.emplace_back(4, 5, 12);

    Kruskal graph = Kruskal(edges, 7);
    vector<Edge> mst = graph.findMST();

    ASSERT_EQ(6, mst[0].getV1());
    ASSERT_EQ(0, mst[0].getV2());
    ASSERT_EQ(2, mst[3].getV1());
    ASSERT_EQ(3, mst[3].getV2());

    ASSERT_EQ(6, mst.size());
    ASSERT_EQ(5, mst[0].getLen());
    ASSERT_EQ(6, mst[1].getLen());
    ASSERT_EQ(6, mst[2].getLen());
    ASSERT_EQ(7, mst[3].getLen());
    ASSERT_EQ(9, mst[4].getLen());
    ASSERT_EQ(9, mst[5].getLen());
    ASSERT_EQ(42, graph.findTotalLength());
}

