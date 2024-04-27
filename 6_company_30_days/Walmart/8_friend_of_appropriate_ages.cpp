#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/friends-of-appropriate-ages/


class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        /**
         * age[y] <= 0.5 * age[x] + 7
         * age[y] > age[x]
         * age[y] > 100 && age[x] < 100
         **/

        int n = ages.size();

        /****** 1st Approach******/
        // int sendRequest = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(i==j || ages[j] <= ages[i]/2 + 7 || ages[j] > ages[i] || (ages[j] > 100 and ages[i] < 100)){
        //             continue;
        //         }

        //         sendRequest++;
        //     }
        // }

        // return sendRequest;

        /******** 2nd Approach ********/
        unordered_map<int, int> mp;
        sort(ages.begin(), ages.end());

        for (int i = 0; i < n; i++)
        {
            if (!mp.count(ages[i]))
                mp[ages[i]] = i;
        }

        int sendRequest = 0;
        for (int i = 0; i < n; i++)
        {
            int idx = lower_bound(ages.begin(), ages.end(), 2 * (ages[i] - 7)) - ages.begin();
            if (idx <= i)
                continue;
            sendRequest += idx - mp[ages[i]] - 1;
        }

        return sendRequest;
    }
};

int main(){
    

    return 0;
}