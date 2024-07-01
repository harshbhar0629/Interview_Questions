#include <bits/stdc++.h>
using namespace std;

/**
 * you are given a integer array of size n which shows the skills of ith worker and integer k 
 * we have to select k element so that E((i=j...i=j+k-1) - k*x) is minimum select any k worker
 */
#define ll long long int
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll k;
        cin >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        vector<ll> pre(n + 1, 0);
        for (int i = 1; i <= n; i++){
            cout << a[i - 1] << " ";
            pre[i] += pre[i - 1] + a[i - 1];
        }
        cout << "\n";

        ll ans = 1e17;
        int i = 1;
        while(i<=n-k+1){
            int j = i + k - 1;
            if(k%2 == 0){
                // even case
                int m1 = (i + j) / 2;
                int m2 = m1 + 1;
                ll l1 = m1 - i;
                ll sum1 = pre[m1-1] - pre[i - 1];
                ll a1 = abs(a[m1 - 1] * l1 - sum1);

                ll l2 = j - m1;
                ll sum2 = pre[j] - pre[m1];
                ll a2 = abs(a[m1 - 1] * l2 - sum2);

                ans = min(ans, a1 + a2);

                ll l11 = m2 - i;
                ll sum11 = pre[m2 - 1] - pre[i - 1];
                ll a11 = abs(a[m2 - 1] * l11 - sum11);

                ll l22 = j - m2;
                ll sum22 = pre[j] - pre[m2];
                ll a22 = abs(a[m2 - 1] * l22 - sum22);

                ans = min(ans, a11 + a22);
            }
            else{
                // odd case
                int m1 = (i + j) / 2;
                ll l1 = m1 - i;
                ll sum1 = pre[m1 - 1] - pre[i - 1];
                ll a1 = abs(a[m1 - 1] * l1 - sum1);

                ll l2 = j - m1;
                ll sum2 = pre[j] - pre[m1];
                ll a2 = abs(a[m1 - 1] * l2 - sum2);

                ans = min(ans, a1 + a2);
            }
            i++;
        }

        cout << ans<<"\n";
    }

    return 0;
}