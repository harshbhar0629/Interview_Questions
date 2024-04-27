#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/

class Solution
{
public:
    int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &specialRoads)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = specialRoads.size();
        vector<int> dis(n, 1e9 + 7);

        for (int i = 0; i < n; i++)
        {
            dis[i] = abs(start[0] - specialRoads[i][0]) + abs(start[1] - specialRoads[i][1]) + specialRoads[i][4];
            pq.push({dis[i], i});
        }

        int ans = abs(target[0] - start[0]) + abs(target[1] - start[1]);

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int idx = curr.second;
            int cost = curr.first;

            if (dis[idx] != cost)
            {
                continue;
            }

            ans = min(ans, cost + abs(target[0] - specialRoads[idx][2]) + abs(target[1] - specialRoads[idx][3]));

            for (int i = 0; i < n; i++)
            {
                int wt = abs(specialRoads[i][0] - specialRoads[idx][2]) + abs(specialRoads[i][1] - specialRoads[idx][3]) + specialRoads[i][4];
                if (cost + wt < dis[i])
                {
                    dis[i] = cost + wt;
                    pq.push({dis[i], i});
                }
            }
            // cout<<ans<<" "<<pq.size()<<endl;
        }

        return ans;
    }
};

int main(){
    

    return 0;
}