#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int len = 0;
        unordered_map<int, int> mp;

        while (i < n)
        {
            mp[nums[i]]++;
            while (j < n and mp[nums[i]] > k)
            {
                mp[nums[j]]--;
                if (mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
                j++;
            }
            // cout<<i<<" "<<j<<endl;
            len = max(len, i - j + 1);
            i++;
        }

        return len;
    }
};

int main(){
    

    return 0;
}