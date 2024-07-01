#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
// https: // www.hackerrank.com/contests/desiqna-oa-practice-contest-00/challenges/a-356/submissions/code/1379558312

int main(){
    int t=1;
    // cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }

        vector<ll> kk(n + 1);
        for (int i = 1; i <= n; i++){
            kk[i] = a[i] ^ b[i];
        }

        ll maxi = 0;
        unordered_map<ll, ll> mp;
        mp[0] = 0;
        ll XOR = 0;
        for (int i = 1; i <= n; i++){
            XOR = (kk[i]) ^ XOR;
            if(mp.find(XOR) == mp.end()){
                mp[XOR] = i;
            }
            else{
                maxi = max(maxi, 1ll*i - mp[XOR]);
            }
        }

        cout << maxi << "\n";
    }

    return 0;
}