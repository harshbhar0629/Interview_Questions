#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/russian-doll-envelopes/

class Solution
{

    int dp[100005];

    int f(vector<vector<int>>& env, int i){
        if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];
        int maxi = INT_MIN;

        for(int j=0; j<i; j++){
            if(env[j][0] < env[i][0] and env[j][1] < env[i][1]){
                maxi = max(maxi, f(env, j));
            }
        }
        if(maxi == INT_MIN) {
            return dp[i] = 1;
        }
        return dp[i] = 1+maxi;
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        memset(dp, -1, sizeof dp);
        int maxi = 1;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());

        for(int i=0; i<n; i++){
            maxi = max(maxi, f(envelopes, i));
        }

        return maxi;

        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
             {
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0]<b[0]; });

        vector<int> lis;
        lis.push_back(envelopes[0][1]);
        for (int i = 1; i < n; i++)
        {
            if (lis.back() < envelopes[i][1])
            {
                lis.push_back(envelopes[i][1]);
            }
            else
            {
                auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        return lis.size();
    }
};

int main(){
    

    return 0;
}