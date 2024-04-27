#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/battleships-in-a-board/

class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] and board[i][j] == 'X')
                {
                    vis[i][j] = 1;
                    cnt++;
                    for (int k = i; k < n; k++)
                    {
                        if (board[k][j] != 'X')
                        {
                            break;
                        }
                        vis[k][j] = 1;
                    }
                    for (int k = j; k < m; k++)
                    {
                        if (board[i][k] != 'X')
                        {
                            break;
                        }
                        vis[i][k] = 1;
                    }
                }
            }
        }

        return cnt;
    }
};


class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (board[i][j] == 'X')
                {
                    cnt++;

                    if (i + 1 < n and board[i + 1][j] == 'X')
                    {
                        for (int k = i; k < n; k++)
                        {
                            if (board[k][j] != 'X')
                            {
                                break;
                            }
                            board[k][j] = '1';
                        }
                    }
                    else if (j + 1 < m and board[i][j + 1] == 'X')
                    {
                        for (int k = j; k < m; k++)
                        {
                            if (board[i][k] != 'X')
                            {
                                break;
                            }
                            board[i][k] = '1';
                        }
                    }
                    else
                    {
                        board[i][j] = '1';
                    }
                }
            }
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}