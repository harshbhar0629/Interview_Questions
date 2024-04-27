#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

#define ll long long int
#define pp pair<char, int>
#define p pair<int, char>
class Solution
{

    void dijkstra(char src, unordered_map<char, vector<pp>> &mp, vector<vector<int>> &costMat)
    {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int wt = curr.first;
            int source = curr.second;

            for (auto it : mp[source])
            {
                if (costMat[src - 'a'][it.first - 'a'] > wt + it.second)
                {
                    costMat[src - 'a'][it.first - 'a'] = wt + it.second;
                    pq.push({costMat[src - 'a'][it.first - 'a'], it.first});
                }
            }
        }
    }

public:
    long long minimumCost(string src, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {

        unordered_map<char, vector<pp>> mp;
        int n = cost.size();
        for (int i = 0; i < n; i++)
        {
            mp[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<int>> costMatrix(26, vector<int>(26, INT_MAX));

        for (int i = 0; i < 26; i++)
        {
            dijkstra(i + 'a', mp, costMatrix);
        }

        ll total_cost = 0;

        for (int i = 0; i < src.size(); i++)
        {
            if (src[i] == target[i])
                continue;
            if (costMatrix[src[i] - 'a'][target[i] - 'a'] == INT_MAX)
            {
                return -1;
            }
            total_cost += costMatrix[src[i] - 'a'][target[i] - 'a'];
        }

        return total_cost;
    }
};

int main(){
    

    return 0;
}