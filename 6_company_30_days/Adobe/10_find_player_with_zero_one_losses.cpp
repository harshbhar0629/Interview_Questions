#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        int dp[100002];
        int N = 1e5 + 2;
        memset(dp, 0, sizeof dp);

        for (auto match : matches)
        {
            int win = match[0];
            int loose = match[1];
            if (dp[win] == 0)
            {
                dp[win] = 1;
            }
            if (dp[loose] == 1)
            {
                dp[loose] = -1;
            }
            else
            {
                dp[loose]--;
            }
        }

        vector<vector<int>> ans(2);

        for (int i = 0; i < N; i++)
        {
            if (dp[i] == 1)
            {
                ans[0].push_back(i);
            }
            if (dp[i] == -1)
            {
                ans[1].push_back(i);
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}