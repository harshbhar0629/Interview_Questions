#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int ans = 0;
        if (left.size() != 0)
        {
            ans = left[left.size() - 1];
        }
        if (right.size() != 0)
        {
            ans = max(n - right[0], ans);
        }

        return ans;
    }
};

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int ans = 0;

        for (auto num : left)
        {
            ans = max(ans, num);
        }

        for (auto num : right)
        {
            ans = max(ans, n - num);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}