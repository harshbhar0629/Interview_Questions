#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+= abs(nums[i]-nums[n/2]);
        // }

        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int val = nums[n / 2];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (abs(val - nums[i]));
        }

        return sum;
    }
};

int main(){
    

    return 0;
}