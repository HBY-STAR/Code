#include <iostream>
#include <vector>
#include <stack>
#include "Edge.cpp"

using namespace std;

class CriticalPath
{
private:
    vector<Edge> graph;
    int nodeCount;

    // You may add some helper functions here

public:
    CriticalPath(vector<Edge> &graph, int nodeCount)
    {
        this->graph = graph;
        this->nodeCount = nodeCount;
    }

    /**
     * @brief Topological sort.
     * @return Sorted edges (precise order does not matter, as long as it's topological).
     * */
    vector<Edge> topologicalSort()
    {
        const int maxNode = 100;
        stack<int> indegreeZero;
        vector<Edge> result;
        int tempV = 0;
        int indegree[maxNode] = {0};
        for (int i = 0; i < graph.size(); i++)
        {
            indegree[graph[i].getEnd()]++;
        }
        for (int i = 0; i < nodeCount; i++)
        {
            if (indegree[i] == 0)
            {
                indegreeZero.push(i);
            }
        }
        while (!indegreeZero.empty())
        {
            tempV = indegreeZero.top();
            indegreeZero.pop();
            for (int i = 0; i < graph.size(); i++)
            {
                if (graph[i].getStart() == tempV)
                {
                    result.push_back(graph[i]);
                    indegree[graph[i].getEnd()]--;
                    if (indegree[graph[i].getEnd()] == 0)
                    {
                        indegreeZero.push(graph[i].getEnd());
                    }
                }
            }
        }
        graph = result;
        return graph;
    }

    /**
     * @brief Earliest time for 'events' (nodes) to take place.
     * @return Earliest time for each node, in node id order, e.g: result[3] is the earliest time for node 3.
     * */
    vector<int> nodesEarliestTime()
    {
        auto result = vector<int>(nodeCount);
        result[0] = 0;
        const int maxNode = 100;
        stack<int> indegreeZero;
        int tempV = 0;
        int indegree[maxNode] = {0};
        int maxTime = 0;
        for (int i = 0; i < graph.size(); i++)
        {
            indegree[graph[i].getEnd()]++;
        }
        for (int i = 0; i < nodeCount; i++)
        {
            if (indegree[i] == 0)
            {
                indegreeZero.push(i);
            }
        }
        while (!indegreeZero.empty())
        {
            tempV = indegreeZero.top();
            indegreeZero.pop();
            for (int i = 0; i < graph.size(); i++)
            {
                if (graph[i].getStart() == tempV)
                {
                    indegree[graph[i].getEnd()]--;
                    if (indegree[graph[i].getEnd()] == 0)
                    {
                        indegreeZero.push(graph[i].getEnd());
                        for (int j = 0; j < graph.size(); j++)
                        {
                            if (graph[j].getEnd() == graph[i].getEnd())
                            {
                                if (graph[j].getWeight() + result[graph[j].getStart()] > maxTime)
                                {
                                    maxTime = graph[j].getWeight() + result[graph[j].getStart()];
                                }
                                result[graph[i].getEnd()] = maxTime;
                            }
                        }
                        maxTime = 0;
                    }
                }
            }
        }
        return result;
    }

    /**
     * @brief Latest time for 'events' (nodes) to take place.
     * @return Latest time for each node, in node id order, e.g: result[3] is the latest time for node 3.
     * */
    vector<int> nodesLatestTime()
    {
        auto result = vector<int>(nodeCount);

        return result;
    }

    /**
     * @brief Earliest time for 'activities' (edges) to take place.
     * @return Earliest time for each edge, in edge id order, e.g: result[3] is the earliest time for edge 3.
     * */
    vector<int> edgesEarliestTime()
    {
        auto result = vector<int>(graph.size());
        vector<int> nodes = nodesEarliestTime();
        for (int i = 0; i < graph.size(); i++)
        {
            result[graph[i].getId()] = nodes[graph[i].getStart()];
        }
        return result;
    }

    /**
     * @brief Latest time for 'activities' (edges) to take place.
     * @return Latest time for each edge, in edge id order, e.g: result[3] is the latest time for edge 3.
     * */
    vector<int> edgesLatestTime()
    {
        auto result = vector<int>(graph.size());
        vector<int> nodes = nodesLatestTime();
        for (int i = 0; i < graph.size(); i++)
        {
            result[graph[i].getId()] = nodes[graph[i].getEnd()] - graph[i].getWeight();
        }
        return result;
    }

    /**
     * @brief Time difference (remaining time) for 'activities' (edges).
     * @return Remaining time for each edge, in edge id order, e.g: result[3] is the remaining time for edge 3.
     * */
    vector<int> timeDifference()
    {
        auto result = vector<int>(graph.size());
        vector<int> early = edgesEarliestTime();
        vector<int> late = edgesLatestTime();
        for (int i = 0; i < result.size(); i++)
        {
            result[i] = late[i] - early[i];
        }
        return result;
    }

    /**
     * @brief Critical path for graph, in START TO END order.
     * @return Critical path, in START TO END order, e.g: v1->v3->v4->v0 should return [e(v1, v3), e(v3, v4), e(v4, v0)]
     * */
    vector<Edge> getCriticalPath()
    {
        auto result = vector<Edge>();
        

        return result;
    }
};
