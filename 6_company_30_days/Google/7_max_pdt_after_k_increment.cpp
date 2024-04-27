#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-product-after-k-increments/description/

#define ll long long int
class Solution
{
    const int N = 1e9 + 7;

public:
    int maximumProduct(vector<int> &nums, int k)
    {

        priority_queue<int, vector<int>, greater<int>>pq(nums.begin(), nums.end());
        while(!pq.empty() and k--){
            int x = pq.top();
            pq.pop();
            pq.push(x+1);
        }

        ll pdt = 1;
        while(!pq.empty()){
            pdt*=pq.top();
            pq.pop();
            pdt %= N;
        }
        return pdt;
    }
};

int main(){
    

    return 0;
}