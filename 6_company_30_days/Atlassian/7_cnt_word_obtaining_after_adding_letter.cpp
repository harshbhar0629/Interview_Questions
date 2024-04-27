#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/

class Solution
{
    int f(vector<string>& startWords, vector<string>& targetWords){
        unordered_map<string,int>mp;
        for(auto it: startWords){
            sort(it.begin(), it.end());
            mp[it]++;
        }

        int cnt=0;

        for(auto it: targetWords){
            sort(it.begin(), it.end());
            for(int i=0; i<it.size(); i++){
                string t = it.substr(0,i) + it.substr(i+1);
                // cout<<t<< " ";
                if(mp.find(t) != mp.end()){
                    cnt++;
                    break;
                }
            }
            // cout<<endl;
        }
        return cnt;
    }

    int bitmask(string &str)
    {
        int res = 0;
        for (auto c : str)
        {
            res += (1 << (c - 'a'));
        }
        return res;
    }

public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {

        unordered_map<int, int> mp;
        for (auto it : startWords)
        {
            int bitmask_value = bitmask(it);
            mp[bitmask_value]++;
        }

        int cnt = 0;
        for (auto it : targetWords)
        {
            int bitmask_val = bitmask(it);
            for (auto c : it)
            {
                int x = bitmask_val - (1 << (c - 'a'));
                if (mp.find(x) != mp.end())
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

int main(){
    

    return 0;
}