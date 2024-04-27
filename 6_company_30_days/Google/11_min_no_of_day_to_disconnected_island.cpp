#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

class Solution
{

    int total_island(vector<vector<int>> &grid)
    {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 and vis[i][j] == 0)
                {
                    cnt++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;

                    while (!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int d = 0; d < 4; d++)
                        {
                            int nr = r + dx[d];
                            int nc = c + dy[d];
                            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                            {
                                continue;
                            }
                            if (grid[nr][nc] != 1 || vis[nr][nc] == 1)
                            {
                                continue;
                            }
                            q.push({nr, nc});
                            vis[nr][nc] = 1;
                        }
                    }
                }
            }
        }
        return cnt;
    }

public:
    int minDays(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        int island = total_island(grid);
        if (island == 0 or island > 1)
        {
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    int _island = total_island(grid);
                    if (_island != 1)
                    {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};

int main(){
    

    return 0;
}