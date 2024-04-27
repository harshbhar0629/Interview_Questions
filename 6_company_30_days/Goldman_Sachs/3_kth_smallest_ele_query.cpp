#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/

class solution{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries){
        int n = nums.size();
        vector<int> res;

        for(auto query: queries){

            int strSize = nums[0].size();
            priority_queue<pair<string,int>>pq;
            for(int i=0; i<n; i++){

                int idx = strSize - query[1];
                string t = nums[i].substr(idx, query[1]);
                
                if(pq.size() < query[0]){
                    pq.push({t, i});
                }
                else if(pq.top().first > t){
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

}