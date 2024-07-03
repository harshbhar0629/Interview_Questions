#include <bits/stdc++.h>
using namespace std;

/**
 * You are given an array an interger n you have to count the good subarrays
 * good subarray: you have to count subarray if you reduces that subarray into zero
 * you can pick any 2 element and you can subtract 2^1 from both the number if bitwise and of ith bit is 1
 */
#define ll long long int
const int MOD = 1e9 + 7;

int solve(vector<int>& v){
    int n = v.size();
    unordered_map<int, ll> mp;
    mp[0]++;
    vector<int> bit(35, 0);
    int cnt = 0;

    for(auto num: v){
        int currZor = 0;
        for (int i = 30; i >= 0; i--){
            int b = (num >> i);
            if(b&1){
                bit[i]++;
            }

            if(bit[i] % 2 != 0){
                currZor |= (1 << i);
            }
        }

        cnt += mp[currZor];
        cnt %= MOD;
        mp[currZor]++;
    }

    return cnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << solve(v)<<"\n";

    return 0;
}