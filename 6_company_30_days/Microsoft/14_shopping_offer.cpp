#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/shopping-offers/

// unbounded_knapsack problem
class Solution
{
    /**
     * TC: without memoization (100*2^(n* max size of each element of needs))
     * TC: with meemoization ()
    */

    map<pair<int, vector<int>>, int> mp;

    int f(int i, vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        if (i == special.size())
        {
            int cost = 0;
            for (int j = 0; j < price.size(); j++)
            {
                cost += price[j] * needs[j];
            }
            return cost;
        }
        if (mp.find({i, needs}) != mp.end())
        {
            return mp[{i, needs}];
        }

        vector<int> need = needs;

        for (int j = 0; j < price.size(); j++)
        {
            need[j] -= special[i][j];
            if (need[j] < 0)
            {
                return f(i + 1, price, special, needs);
            }
        }

        return mp[{i, needs}] = min(f(i + 1, price, special, needs), f(i, price, special, need) + special[i][price.size()]);
    }

public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {

        return f(0, price, special, needs);
    }
};

int main(){
    

    return 0;
}