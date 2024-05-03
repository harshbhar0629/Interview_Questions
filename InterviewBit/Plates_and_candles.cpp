#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/plates-between-candles/

class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = s.size();
        vector<int> candles, prefixSum(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '|')
            {
                candles.push_back(i);
            }
            if (candles.size() > 0 and s[i] == '*')
            {
                prefixSum[i]++;
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (!candles.empty() and candles.back() < i)
            {
                prefixSum[i] = prefixSum[i - 1];
            }
            else
            {
                prefixSum[i] += prefixSum[i - 1];
            }
        }

        vector<int> ans;
        for (auto qu : queries)
        {
            auto left = lower_bound(candles.begin(), candles.end(), qu[0]) - candles.begin();
            auto right = lower_bound(candles.begin(), candles.end(), qu[1]) - candles.begin();
            if (left == candles.size())
            {
                ans.push_back(0);
                continue;
            }

            int idx = (right == candles.size()) ? candles.size() - 1 : right;
            left = candles[left];
            right = candles[idx];

            if (qu[1] < right and idx > 0)
            {
                right = candles[idx - 1];
            }
            if (left >= right)
            {
                ans.push_back(0);
                continue;
            }

            int res = prefixSum[right];
            res -= (left > 0) ? prefixSum[left - 1] : 0;
            ans.push_back(res);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}