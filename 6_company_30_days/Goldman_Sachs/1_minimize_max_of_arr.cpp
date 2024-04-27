#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/

#define ll long long int
class Solution {

    ll gcd(ll a, ll b){
        if(a<b){
            return gcd(b,a);
        }
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }

public:
    int minimizeSet(int _d1, int _d2, int uC1, int uC2) {
        ll d1 = _d1, d2 = _d2;
        ll LCM = (d1*d2)/gcd(d1,d2);
        
        ll lo = 1, hi = 1e12;

        while(lo<=hi){
            ll mid = (lo+hi)>>1;
            ll a = mid/d1;
            ll b = mid/d2;
            if(uC1 <= mid-a and uC2 <= mid-b and uC1 + uC2 <= mid - mid/LCM){
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return lo;
    }
};


int main(){
    

    return 0;
}