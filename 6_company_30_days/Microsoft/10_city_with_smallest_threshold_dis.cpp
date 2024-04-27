#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#define pi pair<int, int>
class Solution
{
    int ans, ansNode;
    int n;
    void bfs(int src, vector<list<pi>> &graph, int threshold)
    {

        vector<int> dis(n, INT_MAX);
        queue<pi> qu;
        dis[src] = 0;
        qu.push({src, 0});

        while (!qu.empty())
        {
            // auto {node, wt} = qu.front();
            // qu.pop();

            // for (auto it : graph[node])
            // {
            //     if (dis[it.first] > it.second + wt)
            //     {
            //         dis[it.first] = it.second + wt;
            //         qu.push({it.first, dis[it.first]});
            //     }
            // }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (dis[i] <= threshold)
            {
                cnt++;
            }
        }

        if (cnt <= ans)
        {
            ans = cnt;
            ansNode = max(ansNode, src);
        }
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int threshold)
    {

        vector<list<pi>> graph(n, list<pi>());
        for (auto edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        ans = INT_MAX;
        ansNode = 0;
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            bfs(i, graph, threshold);
        }

        return ansNode;
    }
};

int main(){
    

    return 0;
}