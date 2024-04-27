#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/stone-game-vi/description/

class Solution
{

    int f(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        vector<vector<int>> score;

        for (int i = 0; i < n; i++)
        {
            score.push_back({a[i] + b[i], a[i], b[i]});
        }

        sort(score.begin(), score.end(), greater<vector<int>>());
        int alice = 0, bob = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                alice += score[i][1];
            }
            else{
            bob += score[i][2];
        }
    }

    if(alice == bob){
        return 0;
    }
    return (alice>bob)? 1: -1;
    }

public:
    int stoneGameVI(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({a[i] + b[i], i});
        }

        int alice = 0, bob = 0;
        bool flag = true;
        while (!pq.empty())
        {
            if (flag)
            {
                alice += a[pq.top().second];
            }
            else
            {
                bob += b[pq.top().second];
            }
            flag = !flag;
            pq.pop();
        }

        if (alice == bob)
        {
            return 0;
        }
        return (alice > bob) ? 1 : -1;
    }
};

int main(){
    

    return 0;
}