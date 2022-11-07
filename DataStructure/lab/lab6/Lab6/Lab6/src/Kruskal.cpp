#include <iostream>
#include <vector>
#include <algorithm>
#include "Edge.cpp"

using namespace std;
const int MaxVertexNum = 1000;

class Kruskal
{
private:
    vector<Edge> edges; // All edges of the graph
    int vertexCount;    // Total number of vertexes in graph

public:
    Kruskal(vector<Edge> &edges, int vertexCount)
    {
        this->edges = edges;
        this->vertexCount = vertexCount;
    }

    int findTotalLength()
    {
        int total = 0;
        for (Edge e : findMST())
        {
            total += e.getLen();
        }
        return total;
    }

    template <typename Comparable>
    void insertsort(vector<Comparable> &a)
    {
        for (int p = 1; p < a.size(); ++p)
        {
            Comparable temp = std::move(a[p]);

            int j;
            for (j = p; j > 0 && temp < a[j - 1]; --j)
                a[j] = std::move(a[j - 1]);
            a[j] = std::move(temp);
        }
    }

    vector<Edge> findMST()
    {
        vector<Edge> result;
        bool inresult[MaxVertexNum] = {false};
        //对edges进行插入排序
        for (int p = 1; p < edges.size(); ++p)
        {
            Edge temp = std::move(edges[p]);
            int j;
            for (j = p; j > 0 && temp.getLen() < edges[j - 1].getLen(); --j)
                edges[j] = std::move(edges[j - 1]);
            edges[j] = std::move(temp);
        }
        for (int p = 0; p < edges.size(); ++p)
        {
            if (inresult[edges[p].getV1()] && inresult[edges[p].getV2()])
            {
                continue;
            }
            else
            {
                result.push_back(edges[p]);
                inresult[edges[p].getV1()] = true;
                inresult[edges[p].getV2()] = true;
            }
        }
        return result;
    }
};
