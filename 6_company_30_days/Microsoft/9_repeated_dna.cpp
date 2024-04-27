#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/repeated-dna-sequences/description/

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {

        if (s.size() < 10)
            return {};
        vector<string> res;
        unordered_map<string, int> mp;

        for (int i = 0; i < s.size() - 9; i++)
        {
            string t = s.substr(i, 10);
            mp[t]++;
        }

        for (auto it : mp)
        {
            if (it.second > 1)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};

int main(){
    

    return 0;
}