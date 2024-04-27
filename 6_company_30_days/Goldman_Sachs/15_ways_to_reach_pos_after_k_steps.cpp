#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

#define ll long long int
const int N = 1e9 + 7;
class Solution
{

    ll dp[2005][1005];
    ll f(int dis, int k)
    {
        if (dis == 0 and k == 0)
            return 1;
        if (dis < 0 || k <= 0)
            return 0;
        if (dp[dis][k] != -1)
            return dp[dis][k];

        return dp[dis][k] = (f(abs(dis - 1), k - 1) % N + f(dis + 1, k - 1) % N) % N;
    }

public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        memset(dp, -1, sizeof dp);
        return f(abs(endPos - startPos), k);
    }
};


int main(){
    

    return 0;
}