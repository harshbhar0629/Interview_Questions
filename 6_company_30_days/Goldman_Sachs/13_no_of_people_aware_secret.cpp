#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-people-aware-of-a-secret/

#define ll long long int
class Solution
{
    int mod = 1e9 + 7;

public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {

        int dp[1005];
        memset(dp, 0, sizeof dp);
        dp[1] = 1;
        ll noOfPeopleSharingSecret = 0;

        for (int i = 2; i <= n; i++)
        {
            int noOfNewPeopleAwareOfSecret = dp[max(0, i - delay)];
            int noOfPeopleForgetSecret = dp[max(0, i - forget)];
            noOfPeopleSharingSecret += (noOfNewPeopleAwareOfSecret - noOfPeopleForgetSecret + mod) % mod;
            dp[i] = noOfPeopleSharingSecret %= mod;
        }

        int totalNoOfPeopleAwareSecret = 0;
        for (int i = n - forget + 1; i <= n; i++)
        {
            totalNoOfPeopleAwareSecret += dp[i];
            totalNoOfPeopleAwareSecret %= mod;
        }

        return totalNoOfPeopleAwareSecret % mod;
    }
};

int main(){
    

    return 0;
}