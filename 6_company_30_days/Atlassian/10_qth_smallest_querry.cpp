#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/query-kth-smallest-trimmed-number/

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> res;

        for (auto query : queries)
        {
            priority_queue<pair<string, int>> pq;
            int strSize = nums[0].size();
            int k = query[0];

            for (int i = 0; i < n; i++)
            {
                int idx = strSize - query[1];
                string t = nums[i].substr(idx, query[1]);
                if (pq.size() < k)
                {
                    pq.push({t, i});
                }
                else if (pq.top().first > t)
                {
                    pq.pop();
                    pq.push({t, i});
                }
            }

            res.push_back(pq.top().second);
        }

        return res;
    }
};

int main(){
    

    return 0;
}