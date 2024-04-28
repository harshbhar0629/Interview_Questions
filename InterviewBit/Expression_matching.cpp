#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/regular-expression-match/discussion/

// In this ques we have to match the pattern string b with string A if B correctly match with A then return A

int f(int i, int j, const string A, const string B, vector<vector<int>>& dp){
    // if both string exhaust simultaneously then return true
    if(i == A.size() and j == B.size()){
        return true;
    }
    // if both not exhaust simultaneously if string B exhaust first then return false
    if(j == B.size()){
        return false;
    }
    // if A exhaust but not string B then check remaining character all are '*' if not then return false
    if(i == A.size()){
        for(; j<B.size(); j++){
            if(B[j] != '*'){
                return false;
            }
        }
        return true;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(A[i] == B[j] || B[j] == '?'){
        return dp[i][j] = f(i+1, j+1, A, B, dp);
    }

    if(B[j] == '*'){
        return dp[i][j] = f(i+1, j, A, B, dp) or f(i, j+1, A, B, dp);
    }

    return dp[i][j] = 0;
}

bool solve(const string A, const string B)
{
    int n = A.size();
    int m = B.size();
    vector<int> curr(m + 2, 0), prev(m + 2, 0);

    prev[0] = 1;
    int l = 1;
    while (l <= m && B[l - 1] == '*')
    {
        prev[l] = 1;
        l++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1] == B[j - 1] || B[j - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (B[j - 1] == '*')
            {
                curr[j] = (prev[j] || curr[j - 1]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return curr[m];
}

int isMatch(const string A, const string B)
{
    // const int n = A.size();
    // const int m = B.size();
    // vector<vector<int>>dp(n+2, vector<int>(m+2, -1));

    // return f(0, 0, A, B, dp);

    return solve(A, B);
}

int main(){
    

    return 0;
}