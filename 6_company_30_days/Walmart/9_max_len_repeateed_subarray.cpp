#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int maxLen = 0;
        int dp[1005][1005];
        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLen = max(dp[i][j], maxLen);
                }
            }
        }

        return maxLen;
    }
};

int main(){
    

    return 0;
}