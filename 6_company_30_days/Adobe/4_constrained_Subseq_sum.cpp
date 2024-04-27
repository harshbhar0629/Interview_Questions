#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/constrained-subsequence-sum/description/

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {

        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        int ans = nums[0];
        pq.push({nums[0], 0});

        for (int i = 1; i < n; i++)
        {
            while (!pq.empty() and i - pq.top().second > k)
            {
                pq.pop();
            }
            int currSum = max(pq.top().first, 0) + nums[i];
            ans = max(ans, currSum);
            pq.push({currSum, i});
        }

        return ans;
    }
};

int main(){
    

    return 0;
}