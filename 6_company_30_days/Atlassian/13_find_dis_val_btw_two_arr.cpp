#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        int m = arr2.size();
        int n = arr1.size();

        for (int i = 0; i < n; i++)
        {
            int l = 0, r = m - 1;
            int x = arr1[i] - d;
            int y = arr1[i] + d;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (arr2[mid] < x)
                {
                    l = mid + 1;
                }
                else if (arr2[mid] > y)
                {
                    r = mid - 1;
                }
                else
                {
                    cnt++;
                    break;
                }
            }
        }
        return n - cnt;
    }
};

int main(){
    

    return 0;
}