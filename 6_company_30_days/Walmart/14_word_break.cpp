#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/word-break/

class Solution
{
    int n, dp[305];

    bool f(string &s, unordered_map<string, int> &mp, int i)
    {
        if (i >= n)
        {
            return true;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        string t = "";
        for (int j = i; j < n; j++)
        {
            t += s[j];
            if (mp.count(t) > 0)
            {
                bool res = f(s, mp, j + 1);
                if (res)
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, int> mp;
        for (auto word : wordDict)
        {
            mp[word]++;
        }

        this->n = s.size();
        memset(dp, -1, sizeof dp);
        return f(s, mp, 0);
    }
};

int main(){
    

    return 0;
}