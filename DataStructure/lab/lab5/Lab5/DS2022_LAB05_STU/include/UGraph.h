//
// Created by HuaJuan on 2022/10/30.
//

#ifndef DS2022_LAB05_STU_UGRAPH_H
#define DS2022_LAB05_STU_UGRAPH_H

#include <vector>
#include <unordered_set>

typedef int VertexType;
const int MaxVerNum = 1000;
using namespace std;

class UGraph
{
private:
    struct ArcNode
    {
        int adjver;
        ArcNode *next;

        ArcNode(int Adjver, ArcNode *Next)
            : adjver{Adjver}, next{Next} {}
        ArcNode()
            : adjver{0}, next{nullptr} {}
        ~ArcNode() {}
    };
    typedef struct VerNode
    {
        VertexType vdate;
        ArcNode *edge;

        VerNode(VertexType &Vdate, ArcNode *Edge)
            : vdate{Vdate}, edge{Edge} {}
        VerNode()
            : vdate{0}, edge{nullptr} {}
        ~VerNode()
        {
            ArcNode *temp1 = edge;
            ArcNode *temp2;
            while (temp1 != nullptr)
            {
                temp2 = temp1->next;
                delete temp1;
                temp1 = temp2;
            }
        }
    } VerNode, AdjList[MaxVerNum];

    AdjList vertexs;
    int vernum, arcnum;

public:
    explicit UGraph(int nodeCnt);
    UGraph(const UGraph &rhs);
    ~UGraph(){};
    void dfs_inside(int node, vector<int> &result, bool visited[MaxVerNum]) const;

public:
    [[nodiscard]] int nodeCnt() const;

    void addEdge(int x, int y);

    [[nodiscard]] bool isAdjacent(int x, int y) const;

    [[nodiscard]] std::vector<int> adjacentNodes(int x) const;

    [[nodiscard]] std::vector<int> bfs(int start) const;

    [[nodiscard]] std::vector<int> dfs(int start) const;
};

#endif // DS2022_LAB05_STU_UGRAPH_H
