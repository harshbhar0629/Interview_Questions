#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/the-skyline-problem/

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        multiset<int> mul{0};
        vector<pair<int, int>> v;
        vector<vector<int>> ans;

        for (auto building : buildings)
        {
            v.push_back({building[0], -building[2]});
            v.push_back({building[1], building[2]});
        }

        sort(v.begin(), v.end());
        int ongoingHeight = 0;

        for (int i = 0; i < v.size(); i++)
        {
            int currentPoint = v[i].first;
            int currHeight = v[i].second;
            if (currHeight < 0)
            {
                mul.insert(-currHeight);
            }
            else
            {
                mul.erase(mul.find(currHeight));
            }

            int maxHeight = *mul.rbegin();
            if (ongoingHeight != maxHeight)
            {
                ongoingHeight = maxHeight;
                ans.push_back({currentPoint, maxHeight});
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}