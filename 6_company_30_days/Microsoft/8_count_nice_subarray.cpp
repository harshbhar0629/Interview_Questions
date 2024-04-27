#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int cnt = 0, nice_subarray = 0;
        int n = nums.size();
        int i = 0, j = 0, odd = 0;

        while (i < n)
        {
            if (nums[i] % 2)
            {
                cnt = 0;
                odd++;
            }
            while (j < n and odd >= k)
            {
                cnt++;
                if (nums[j] % 2)
                    odd--;
                j++;
            }
            nice_subarray += cnt;
            i++;
        }
        return nice_subarray;
    }
};

int main(){
    

    return 0;
}