#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#define ll long long int

class Solution
{
public:
    // O(n^2)
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        vector<int> ans(2);
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == arr[j])
                {
                    cnt++;
                }
            }
            if (cnt == 2)
            {
                ans[0] = i;
            }
            else if (cnt == 0)
            {
                ans[1] = i;
            }
        }
        return ans;
    }

   
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // cycle sort
        int i = 0;
        while (i < n)
        {
            if (arr[i] != arr[arr[i] - 1])
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
            else
                i++;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                return {arr[i], i + 1};
            }
        }
        return {};
    }

    vector<int> findTwoElement(vector<int> arr, int n)
    {
        unordered_map<int, int> mp;
        ll sum = 0;
        vector<int> ans(2);
        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i]) != mp.end())
            {
                ans[0] = arr[i];
                continue;
            }
            mp[arr[i]]++;
            sum += arr[i];
        }
        ll _n = n;
        ll val = (_n * (_n + 1)) / 2 - sum;
        ans[1] = val;
        return ans;
    }
};



int main(){
    

    return 0;
}