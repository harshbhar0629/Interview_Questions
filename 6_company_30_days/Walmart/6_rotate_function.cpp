#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/rotate-function/description/

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {

        /**
            arr = [4 3 2 6]
            f(0) = 25
            sum = 15
            f(1) = 16, f(2) = 23
            f(1) = f(0) + sum - n*arr[n-1]
            f(2) = f(1) + sum - n*arr[n-2]
            f(i) = f(i-1) + sum - n*arr[n-i]
        */

        int n = nums.size();
        int sum = 0, f_0 = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            f_0 += i * nums[i];
        }
        maxSum = f_0;

        vector<int> dp(n, 0);
        dp[0] = f_0;

        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + sum - n * nums[n - i];
            maxSum = max(dp[i], maxSum);
        }

        return maxSum;

        // int n = nums.size();
        // int maxSum = INT_MIN;
        // for(int i=0; i<n; i++){
        //     int sum=0;
        //     int t = n, x=0, j=i;
        //     while(t--){
        //         sum+=nums[j]*x;
        //         j++, x++;
        //         if(j==n) j=0;
        //     }
        //     maxSum = max(maxSum, sum);
        // }
        // return maxSum;
    }
};

int main(){
    

    return 0;
}