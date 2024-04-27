#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution
{
public:
    int findPairs(vector<int> &nums, int k){
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int cnt = 0;

        if(k==0){
            for(auto it: mp){
                if(it.second > 1){
                    cnt++;
                }
            }
        }
        else{
            for(auto it: mp){
                int ele = it.first - k;
                if(mp.count(ele) > 0){
                    cnt++;
                }
            }
        }

        return cnt;
    }

    int findPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, ans = 0, j = 1;
        sort(nums.begin(), nums.end()); // O(nlogn) sc:(sort algo)
        for (; i < n and j < n;)
        {
            if (i == j or nums[j] - nums[i] < k)
            {
                j++;
            }
            else
            {
                if (nums[j] - nums[i] == k)
                {
                    ans++;
                    j++;
                    for (; j < n; j++)
                    {
                        if (nums[j] != nums[j - 1])
                        {
                            break;
                        }
                    }
                    if (j == n)
                    {
                        return ans;
                    }
                    j--;
                }
                i++;
                while (i < j and nums[i] == nums[i - 1])
                {
                    i++;
                }
            }
        }
        return ans;
    }
};

int main(){


    return 0;
}