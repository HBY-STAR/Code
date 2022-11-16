//
// Created by HuaJuan on 2022/11/13.
//
#include "MaxTransmissionProbaProlem.h"

double maxTransmissionProba(int n,
                            const std::vector<std::vector<int>> &links,
                            const std::vector<double> &successProbas,
                            int start,
                            int end)
{
    //这里定义最大顶点数为100
    const int MaxVer = 3;
    std::vector<int> marked;
    double prob[MaxVer][MaxVer] = {0};
    double result[MaxVer] = {0};
    double maxProb = 0;
    int maxTag[2] = {-1, -1};
    int markTag = 1;
    for (int i = 0; i < links.size(); i++)
    {
        prob[links[i][0]][links[i][1]] = successProbas[i];
        prob[links[i][1]][links[i][0]] = successProbas[i];
    }

    marked.push_back(start);
    prob[start][start] = 1;
    result[start] = 1;
    while (marked.size() < n)
    {
        for (int i = 0; i < marked.size(); i++)
        {
            for (int j = 0; j < MaxVer; j++)
            {
                markTag = 1;
                for (int k = 0; k < marked.size(); k++)
                {
                    if (marked[k] == j)
                    {
                        markTag = 0;
                    }
                }
                if (markTag && prob[marked[i]][j] * result[marked[i]] > maxProb)
                {
                    maxProb = prob[marked[i]][j] * result[marked[i]];
                    maxTag[0] = marked[i];
                    maxTag[1] = j;
                }
            }
        }
        result[maxTag[1]] = maxProb;
        marked.push_back(maxTag[1]);
        prob[maxTag[1]][maxTag[1]] = 1;
        maxProb = 0;
        maxTag[0] = -1;
        maxTag[1] = -1;
    }
    return result[end];
}
