//
// Created by HuaJuan on 2022/10/30.
//

#include "UGraph.h"
#include <queue>
#include <list>

using namespace std;

UGraph::UGraph(int nodeCnt)
{
    vernum = nodeCnt;
}

int UGraph::nodeCnt() const
{
    return vernum;
};

void UGraph::addEdge(int x, int y)
{
    if (!isAdjacent(x, y) && x < vernum && y < vernum)
    {
        ArcNode *temp;
        if (vertexs[x].edge == nullptr)
        {
            vertexs[x].edge = new ArcNode(y, nullptr);
        }
        else
        {
            temp = vertexs[x].edge->next;
            vertexs[x].edge = new ArcNode(y, temp);
        }
        if (vertexs[y].edge == nullptr)
        {
            vertexs[y].edge = new ArcNode(x, nullptr);
        }
        else
        {
            temp = vertexs[y].edge->next;
            vertexs[y].edge = new ArcNode(x, temp);
        }
        arcnum++;
    }
}

bool UGraph::isAdjacent(int x, int y) const
{
    if (x < vernum && y < vernum)
    {
        ArcNode *temp = vertexs[x].edge;
        while (temp != nullptr)
        {
            if (temp->adjver == y)
            {
                return 1;
            }
            temp = temp->next;
        }
    }
    return 0;
}

std::vector<int> UGraph::adjacentNodes(int x) const
{
    vector<int> result;
    ArcNode *temp = vertexs[x].edge;
    while (temp != nullptr)
    {
        result.push_back(temp->adjver);
        temp = temp->next;
    }
    return result;
}

std::vector<int> UGraph::bfs(int start) const
{
    // TODO
}

std::vector<int> UGraph::dfs(int start) const
{
    // TODO
}
