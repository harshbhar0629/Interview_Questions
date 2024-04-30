#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/

int dp[100005][5];
int f(int i, bool isGoing, const vector<int> &A)
{
    if (i == A.size())
    {
        return 0;
    }
    if (dp[i][isGoing] != -1)
    {
        return dp[i][isGoing];
    }

    // skip the current transition no matter either isGoing transition or not
    int ans = f(i + 1, isGoing, A);
    if (isGoing)
    {
        // try to complete transition
        ans = max(ans, A[i] + f(i + 1, !isGoing, A));
    }
    else
    {
        // try to make transition
        ans = max(ans, f(i + 1, !isGoing, A) - A[i]);
    }

    return dp[i][isGoing] = ans;
}

int maxProfit(const vector<int> &A)
{
    memset(dp, -1, sizeof dp);
    return f(0, false, A);
}

int main(){
    

    return 0;
}