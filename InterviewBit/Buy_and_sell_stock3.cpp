#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

// int dp[700005][2][3];
// int f(int i, int isGoing, int k, const vector<int>& A){
//     if(i == A.size() || k == 0){
//         return 0;
//     }
//     if(dp[i][isGoing][k] != -1){
//         return dp[i][isGoing][k];
//     }

//     // skip the current transition or tolerate to complete the current transition
//     int ans = f(i+1, isGoing, k, A);
//     if(isGoing){
//         // complete the transition ans also decrease the k as well bcoz k denotes the transition
//         ans = max(ans, A[i] + f(i+1, !isGoing, k-1, A));
//     }
//     else{
//         // try to make or start the transition
//         ans = max(ans, f(i+1, !isGoing, k, A) - A[i]);
//     }

//     return dp[i][isGoing][k] = ans;
// }

int fbu(const vector<int> &A)
{
    const int n = A.size();
    // memset(dp, 0, sizeof dp);
    vector<vector<int>> next(5, vector<int>(5, 0)), curr(5, vector<int>(5, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int isGoing = 1; isGoing >= 0; isGoing--)
        {
            for (int k = 1; k <= 2; k++)
            {

                // int ans = dp[i+1][isGoing][k];
                int ans = next[isGoing][k];

                if (isGoing)
                {
                    // complete the transition ans also decrease the k as well bcoz k denotes the transition
                    // ans = max(ans, A[i] + dp[i+1][0][k-1]);
                    ans = max(ans, A[i] + next[0][k - 1]);
                }
                else
                {
                    // try to make or start the transition
                    // ans = max(ans, dp[i+1][1][k] - A[i]);
                    ans = max(ans, next[1][k] - A[i]);
                }
                curr[isGoing][k] = ans;
            }
        }
        next = curr;
    }
    return curr[0][2];
}

int maxProfit(const vector<int> &A)
{
    // memset(dp, -1, sizeof dp);
    // return f(0, false, 2, A);
    return fbu(A);
}

int main(){
    

    return 0;
}