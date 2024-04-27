#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/combination-sum-iii/submissions/1137441475/


class solution{
    vector<vector<int>> ans;

    void f(int n, int k, int i, vector<int> &v)
    {
        if (v.size() == k and n == 0)
        {
            ans.push_back(v);
            return;
        }
        if (v.size() >= k)
            return;

        for (int j = i; j <= 9; j++)
        {
            if (n - j >= 0)
            {
                v.push_back(j);
                f(n - j, k, j + 1, v);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> v;
        f(n, k, 1, v);
        return ans;
    }
};

int main(){

}