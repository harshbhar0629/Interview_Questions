#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/palindrome-partitioning-ii/

bool isPalindrome(int i, int j, const string &A)
{
    while (i < j)
    {
        if (A[i] != A[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}

int dp[505];
int f(int i, const string &A)
{
    if (i >= A.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int ans = 1e8;
    for (int j = i; j < A.size(); j++)
    {
        if (isPalindrome(i, j, A))
        {
            int cut = 1 + f(j + 1, A);
            ans = min(ans, cut);
        }
    }

    return dp[i] = ans;
}

int minCut(string A)
{
    if (A.size() <= 1)
    {
        return 0;
    }
    memset(dp, -1, sizeof dp);
    return f(0, A) - 1;
}

int main(){
    

    return 0;
}