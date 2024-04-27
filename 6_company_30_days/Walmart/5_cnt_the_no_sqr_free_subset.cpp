#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-the-number-of-square-free-subsets/

#define ll long long int
const int mod = 1e9 + 7;
const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
class Solution
{
    // TC: (2^n)(n+p)
    int ans=0;
    void f(vector<int>& nums, vector<int>&v, int i){
        if(i == nums.size()){
            if(v.size() == 0){
                return;
            }
            ll pdt = 1;
            for(int j=0; j<v.size(); j++){
                pdt*=v[j];
            }

            for(auto p: primes){
                int cnt=0;
                ll product = pdt;
                // cout<<pdt<<" "<<p;
                while(pdt % p == 0){
                    cnt++;
                    pdt/=p;
                }
                pdt = product;
                if(cnt>1){
                    return ;
                }
            }
            ans++;
            return;
        }

        f(nums, v, i+1);
        v.push_back(nums[i]);
        f(nums, v, i+1);
        v.pop_back();
    }

    ll dp[1024][1024 + 4];

    ll f1(vector<int> &nums, int i, int mask)
    {
        if (i == nums.size())
        {
            return 1;
        }
        if (dp[i][mask] != -1)
        {
            return dp[i][mask];
        }

        int temp = mask, flag = 1;

        for (int j = 0; j < 10; j++)
        {
            int num = nums[i], cnt = 0;
            while (num % primes[j] == 0)
            {
                num /= primes[j];
                cnt++;
            }
            if (cnt >= 2 or (cnt == 1 and ((mask >> j) & 1)))
            {
                flag = 0;
                break;
            }
            if (cnt)
            {
                temp = temp | (1 << j);
            }
        }
        if (flag)
        {
            return dp[i][mask] = (f1(nums, i + 1, mask) + f1(nums, i + 1, temp)) % mod;
        }
        else
        {
            return dp[i][mask] = f1(nums, i + 1, mask);
        }
    }

public:
    int squareFreeSubsets(vector<int> &nums)
    {
        // vector<int>v;
        // f(nums, v, 0);
        // return ans;
        memset(dp, -1, sizeof dp);
        return 1ll * (f1(nums, 0, 0) - 1 + mod) % mod;
    }
};

int main(){
    

    return 0;
}