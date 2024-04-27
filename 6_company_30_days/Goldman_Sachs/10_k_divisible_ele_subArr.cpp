#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/k-divisible-elements-subarrays/

class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {

        int n = nums.size();
        set<vector<int>> all;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            int cnt = 0;
            for (int j = i; j < n; j++)
            {
                v.push_back(nums[j]);
                if (nums[j] % p == 0)
                    cnt++;
                if (cnt <= k)
                {
                    all.insert(v);
                }
                else
                {
                    break;
                }
            }
        }
        return all.size();
    }
};

int main(){
    

    return 0;
}