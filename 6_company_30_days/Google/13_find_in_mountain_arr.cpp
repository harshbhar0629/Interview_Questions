#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-in-mountain-array/

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int lo = 0, hi = n - 1;

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (mountainArr.get(mid) <= mountainArr.get(mid + 1))
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        int idx = lo;
        lo = 0, hi = idx;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        lo = idx + 1, hi = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) > target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}