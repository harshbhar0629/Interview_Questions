#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n, k;
bool check(int g, vector<ll>& a){
    int i = 0;
    ll grp = k * g;
    while(i<a.size()){
        if(g < a[i]){
            grp -= g;
        }
        else{
            grp -= a[i];
        }
        i++;
    }

    if(grp <= 0){
        return true;
    }
    return false;
}

int main(){
    cin >> n >> k;
    ll sum = 0;
    vector<ll> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    int ans = 0;
    ll lo = 1, hi = sum;
    while(lo <= hi){
        ll mid = lo + (hi - lo) / 2;
        if(check(mid, a)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }


    // for (int i = 1; i <= sum; i++){
    //     if(check(i, a)){
    //         ans = i;
    //     }
    //     else {
    //         break;
    //     }
    // }
    cout << ans << "\n";

    return 0;
}
