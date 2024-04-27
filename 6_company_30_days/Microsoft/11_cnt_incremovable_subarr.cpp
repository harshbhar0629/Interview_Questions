#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/

class Solution
{

    // bool f(vector<int>& nums, int i, int j){
    //     int prev = INT_MIN;
    //     for(int k=0; k<nums.size(); k++){
    //         if(k>=i and k<=j){
    //             continue;
    //         }
    //         if(prev >= nums[k]) return false;
    //         prev = nums[k];
    //     }
    //     return true;
    // }

public:
    int incremovableSubarrayCount(vector<int> &nums)
    {

        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         if(f(nums, i, j)) cnt++;
        //     }
        // }
        // return cnt;

        int n = nums.size();
        vector<int> left, right;
        int i = 0;
        while (i < n - 1 and nums[i] < nums[i + 1])
        {
            left.push_back(nums[i]);
            i++;
        }
        left.push_back(nums[i]);

        int j = n - 1;
        while (j > 0 and nums[j - 1] < nums[j])
        {
            right.push_back(nums[j]);
            j--;
        }
        right.push_back(nums[j]);
        reverse(right.begin(), right.end());
        int right_size = right.size();
        int cnt = (i == n - 1) ? 0 : (n - j + 1);

        for (int k = 0; k < left.size(); k++)
        {
            int idx = upper_bound(right.begin(), right.end(), left[k]) - right.begin();
            cnt += (right_size - idx) + 1;
        }

        return cnt;

    }
};

int main(){
    

    return 0;
}