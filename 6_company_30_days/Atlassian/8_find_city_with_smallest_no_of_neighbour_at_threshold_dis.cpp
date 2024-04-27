#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution
{
    vector<list<pair<int, int>>> graph;
    int n;
    int maxi, ans;

    void f(int src, int threshold)
    {
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;

        while (!q.empty())
        {
            auto curr = q.front();
            int node = curr.first;
            int wt = curr.second;
            q.pop();

            for (auto it : graph[node])
            {
                if (dis[it.first] > wt + it.second)
                {
                    dis[it.first] = it.second + wt;
                    q.push({it.first, dis[it.first]});
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (dis[i] <= threshold)
            {
                cnt++;
            }
        }

        if (cnt <= maxi)
        {
            maxi = cnt;
            ans = max(ans, src);
        }
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        graph.resize(n, list<pair<int, int>>());
        for (auto edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        this->n = n;
        this->ans = 0;
        this->maxi = n + 1;

        for (int i = 0; i < n; i++)
        {
            f(i, distanceThreshold);
        }

        return ans;
    }
};

int main(){
   

    return 0;
}