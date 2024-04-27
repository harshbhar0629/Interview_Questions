#include<bits/stdc++.h>
using namespace std;
// https : // leetcode.com/problems/high-access-employees/submissions/1137434936/

class solution{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times){
        
        unordered_map<string, vector<int>> mp;
        for(auto& it: access_times){
            mp[it[0]].push_back(stoi(it[1]));
        }

        vector<string> res;

        for(auto& it: mp){
            if(it.second.size() >= 3){
                vector<int>& v = it.second;
                sort(v.begin(), v.end(), [](int &x, int &y)
                     { return x < y; });
                for (int i = 2; i < v.size(); i++)
                {
                    if(v[i] - v[i-2] < 100){
                        res.push_back(it.first);
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    
}