#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/largest-divisible-subset/description/

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        sort(nums.begin(), nums.end());
        int idx = 0, maxi = 1;

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 and dp[i] < 1 + dp[j])
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (maxi < dp[i])
            {
                idx = i;
                maxi = dp[i];
            }
        }

        vector<int> ans;
        ans.push_back(nums[idx]);

        while (idx != hash[idx])
        {
            idx = hash[idx];
            ans.push_back(nums[idx]);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}