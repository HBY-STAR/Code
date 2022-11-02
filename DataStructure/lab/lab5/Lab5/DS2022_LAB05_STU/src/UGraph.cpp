//
// Created by HuaJuan on 2022/10/30.
//

#include "UGraph.h"
#include <queue>
#include <list>

using namespace std;

UGraph::UGraph(int nodeCnt = 0)
{
    vernum = nodeCnt;
}

UGraph::UGraph(const UGraph &rhs)
{
    vernum = rhs.vernum;
    arcnum = rhs.arcnum;
    ArcNode *temp;
    for (int i = 0; i < vernum; i++)
    {
        temp = rhs.vertexs[i].edge;
        while (temp != nullptr)
        {
            this->addEdge(i, temp->adjver);
            temp = temp->next;
        }
    }
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
            temp = vertexs[x].edge;
            vertexs[x].edge = new ArcNode(y, temp);
        }
        if (x != y)
        {
            if (vertexs[y].edge == nullptr)
            {
                vertexs[y].edge = new ArcNode(x, nullptr);
            }
            else
            {
                temp = vertexs[y].edge;
                vertexs[y].edge = new ArcNode(x, temp);
            }
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
    vector<int> result;
    if (start >= vernum)
    {
        return result;
    }
    else
    {
        bool visited[vernum] = {false};
        queue<int> level;
        level.push(start);
        result.push_back(start);
        visited[start] = true;
        int tempv;
        ArcNode *tempa;
        while (!level.empty())
        {
            tempv = level.front();
            level.pop();
            tempa = vertexs[tempv].edge;
            while (tempa != nullptr)
            {
                if (!visited[tempa->adjver])
                {
                    level.push(tempa->adjver);
                    result.push_back(tempa->adjver);
                    visited[tempa->adjver] = true;
                }
                tempa = tempa->next;
            }
        }
        return result;
    }
}

void UGraph::dfs_inside(int node, vector<int> &result, bool visited[MaxVerNum]) const
{
    ArcNode *temp = vertexs[node].edge;
    visited[node] = true;
    result.push_back(node);
    while (temp != nullptr)
    {
        if (!visited[temp->adjver])
        {
            dfs_inside(temp->adjver, result, visited);
        }
        temp = temp->next;
    }
}

std::vector<int> UGraph::dfs(int start) const
{
    vector<int> result;
    bool visited[MaxVerNum] = {false};
    if (start >= vernum)
    {
        return result;
    }
    else
    {
        dfs_inside(start, result, visited);
        return result;
    }
}
