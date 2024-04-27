#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/special-permutations/

class Solution
{
    int cnt;
    int N = 1e9 + 7;
    bool special(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (!(nums[i] % nums[i + 1] == 0 || nums[i + 1] % nums[i] == 0))
            {
                return false;
            }
        }
        return true;
    }

    void f(vector<int> &nums, int i)
    {
        int n = nums.size();
        if (i >= n)
        {
            if (special(nums))
            {
                cnt++;
                cnt %= N;
            }
            return;
        }
        // T = n*T(n-1) + O(1)
        for (int k = i; k < n; k++)
        {
            if (k != i and nums[i] == nums[k])
                continue;
            swap(nums[i], nums[k]);
            f(nums, i + 1);
            swap(nums[i], nums[k]);
        }
    }

public:
    int specialPerm(vector<int> &nums)
    {
        cnt = 0;
        f(nums, 0);
        return cnt;
    }
};

/****************************** Approach-2 ******************************/
class Solution
{
    int N = 1e9 + 7;
    int f(int i, int &prev, vector<int> &nums, vector<int> &vis)
    {
        int n = nums.size();
        if (i >= n)
        {
            return 1;
        }

        int res = 0;
        for (int k = 0; k < n; k++)
        {
            if (vis[k] || (prev != -1 and nums[k] % nums[prev] != 0 and nums[prev] % nums[k] != 0))
            {
                continue;
            }
            vis[k] = true;
            res += f(i + 1, k, nums, vis);
            vis[k] = false;
        }
        return res;
    }

public:
    int specialPerm(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> vis(n, 0);
        int prev = -1;
        return f(0, prev, nums, vis);
    }
};

/****************************** Approach-3 ******************************/
// TC: O(15*(1<<15));
class Solution
{

    int N = 1e9 + 7;
    int dp[15][1 << 15];

    int f(int i, int prev, int mask, vector<int> &nums)
    {
        int n = nums.size();
        // if our pointer reach to end means we have reached the destination so this is a one way to reach
        if (i >= n)
        {
            return 1;
        }
        // if any state is previously computed then return that state
        if (dp[prev][mask] != -1)
        {
            return dp[prev][mask] % N;
        }

        long long int res = 0;
        for (int k = 0; k < n; k++)
        {
            // if our set bit is (1) then already visited
            if (mask & (1 << k))
            {
                continue;
            }
            // if mask is not zero and it is also not divisible by anyone so continue this is a redundant case (pruning call)
            if (mask != 0 and nums[k] % nums[prev] != 0 and nums[prev] % nums[k] != 0)
            {
                continue;
            }
            // store all ways to reach destination
            res += f(i + 1, k, mask | (1 << k), nums) % N;
        }
        // return all ways
        return dp[prev][mask] = res % N;
    }

public:
    int specialPerm(vector<int> &nums)
    {
        memset(dp, -1, sizeof dp);
        return f(0, 0, 0, nums);
    }
};

int main()
{

    return 0;
}