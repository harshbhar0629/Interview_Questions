#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/map-of-highest-peak/

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {

        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> dis(n, vector<int>(m, -1));
        queue<pair<int, int>> qu;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    qu.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
        while (!qu.empty())
        {
            pair<int,int>curr = qu.front();
            qu.pop();
            int r = curr.first;
            int c = curr.second;

            for (int d = 0; d < 4; d++)
            {
                int nr = dir[d].first + r;
                int nc = dir[d].second + c;
                if (nr < 0 || nc < 0 || nc >= m || nr >= n || dis[nr][nc] != -1)
                {
                    continue;
                }
                dis[nr][nc] = 1 + dis[r][c];
                qu.push({nr, nc});
            }
        }
        return dis;
    }
};

int main(){
    

    return 0;
}