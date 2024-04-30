#include <bits/stdc++.h>
using namespace std;
/**
 * https://www.interviewbit.com/problems/distinct-subsequences/
 * Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.
 *
*/

int dp[705][705];
int f(const string &A, const string &B, int i, int j)
{
    if (j == B.size())
        return 1;
    if (i == A.size())
        return 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // skip current character why only ith pointer will inc bcoz we have to make distinct subseq in string A
    int ans = f(A, B, i + 1, j);
    if (A[i] == B[j])
    {
        ans += f(A, B, i + 1, j + 1);
    }

    return dp[i][j] = ans;
}

int numDistinct(string A, string B)
{
    memset(dp, -1, sizeof dp);
    return f(A, B, 0, 0);
}

int main(){
    

    return 0;
}