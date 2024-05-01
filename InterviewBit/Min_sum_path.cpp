#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/min-sum-path-in-matrix/

int f(int i, int j, const vector<vector<int>> &A, vector<vector<int>> &dp)
{
    if (i == A.size() - 1 and j == A[0].size() - 1)
    {
        return A[i][j];
    }
    if (i == A.size() || j == A[0].size())
    {
        return 1e8;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int down = f(i + 1, j, A, dp);
    int right = f(i, j + 1, A, dp);

    return dp[i][j] = A[i][j] + min(down, right);
}

int minPathSum(vector<vector<int>> &A)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(A[0].size() + 1, -1));
    return f(0, 0, A, dp);
}

int main(){
    

    return 0;
}