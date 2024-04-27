#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/

#define ll long long int
class Solution
{
    int N = 1e9 + 7;
    ll power(ll x, ll times)
    {
        if (times == 0)
        {
            return 1;
        }
        ll ans = power(x, times / 2);
        ans = ((ans % N) * (ans % N)) % N;
        if (times % 2)
        {
            return ((ans % N) * (x % N)) % N;
        }
        return ans;
    }

public:
    int minNonZeroProduct(int p)
    {
        // x/2 terms are 1 so we will not consider bcoz of its set bit 
        // x*y > (x+1)*(y-1) so every time we will just follow this property
        ll x = (1ll << p) - 1;
        return (x % N * power(x - 1, x / 2) % N) % N;
    }
};

int main(){
    

    return 0;
}