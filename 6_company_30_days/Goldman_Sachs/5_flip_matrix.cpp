#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/random-flip-matrix/

class Solution
{

    // map<pair<int,int>, int>mp;
    int m, n;
    int i, j;

public:
    Solution(int m, int n)
    {
        this->m = m;
        this->n = n;
        this->i = 0;
        this->j = 0;
    }

    vector<int> flip()
    {
        vector<int> ans = {i, j};
        if (++j == n)
        {
            j = 0;
            if (++i == m)
            {
                i = 0;
            }
        }
        return ans;
        // int i = rand()%m;
        // int j = rand()%n;
        // if(mp.find({i,j}) == mp.end()){
        //     mp[{i,j}] = 1;
        //     return {i,j};
        // }
        // return flip();
    }

    void reset()
    {
        // mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

int main(){

}