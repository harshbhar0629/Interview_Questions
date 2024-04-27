#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();

        /******  1st Approach  ******/
        // int len=0;
        // for(int i=0; i<n; i++){
        //     int cost=0;
        //     for(int j=i; j<n; j++){
        //         cost += abs(s[j] - t[j]);
        //         if(cost>maxCost) break;
        //         len = max(len, j-i+1);
        //     }
        // }
        // return len;

        /*******  2nd Approach  *******/
        // vector<int>cost(n,0);

        // for(int i=0; i<n; i++){
        //     int diff = abs(s[i] - t[i]);
        //     cost[i] = diff;
        // }

        // int i=0, j=0, len=0, sum=0;
        // while(j<n){
        //     sum+=cost[j];
        //     while(i<n and sum>maxCost){
        //         sum-=cost[i];
        //         i++;
        //     }
        //     len = max(len, j-i+1);
        //     j++;
        // }
        // return len;

        /********  3rd Approach  **********/

        int i = 0, j = 0, len = 0;
        int cost = 0;

        while (j < n)
        {
            cost += abs(s[j] - t[j]);
            while (i < n and cost > maxCost)
            {
                cost -= abs(s[i] - t[i]);
                i++;
            }
            len = max(len, j - i + 1);
            j++;
        }

        return len;
    }
};

int main(){
    

    return 0;
}