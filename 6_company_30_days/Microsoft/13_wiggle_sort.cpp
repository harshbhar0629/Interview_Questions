#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/wiggle-sort-ii/description/

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res(n);
        if (n <= 1)
            return;

        int j = n - 1, i = 1;
        while (j >= 0)
        {
            res[i] = nums[j];
            i += 2;
            j--;
            if (i >= n)
                i = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        nums = res;
    }
};

int main(){
    

    return 0;
}