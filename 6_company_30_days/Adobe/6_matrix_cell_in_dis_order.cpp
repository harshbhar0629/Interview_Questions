#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/matrix-cells-in-distance-order/description/

#define pi pair<int, int>
#define pii pair<int, pair<int, int>>
class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r, int c)
    {

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        vector<vector<int>> res;
        queue<pii> qu;
        vector<pii> dis;
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        qu.push({0, {r, c}});
        vis[r][c] = 1;

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();

            int dist = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            dis.push_back({dist, {x, y}});

            for (int d = 0; d < 4; d++)
            {
                int i = x + dx[d];
                int j = y + dy[d];
                if (i < 0 || j < 0 || i >= rows || j >= cols)
                {
                    continue;
                }
                if (vis[i][j])
                {
                    continue;
                }
                vis[i][j] = 1;
                qu.push({dist + 1, {i, j}});
            }
        }

        sort(dis.begin(), dis.end());
        for (int i = 0; i < dis.size(); i++)
        {
            res.push_back({dis[i].second.first, dis[i].second.second});
        }

        return res;
    }
};

int main()
{

    return 0;
}