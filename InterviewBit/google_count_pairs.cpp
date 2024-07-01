#include <bits/stdc++.h>
using namespace std;

/**
 * count pairs 
 * 1<=i<j<n
 * (a[i]-a[j]+c == b[i]-b[j]+d)
 * simplify this eqn
 * (a[i]-b[i] + c) == (a[j]-b[j]+d)
 */

int solve(vector<int>& a, vector<int>& b, int c, int d){
    int ans = 0;
    const int n = a.size();
    unordered_map<int, int> mp;
    for (int i = 1; i < n; i++){
        mp[a[i] - b[i] + d]++;
    }

    ans += mp[a[0] - b[0] + c];

    for(int i = 1; i < n-1; i++){
        mp[a[i] - b[i] + d]--;
        ans += mp[a[i] - b[i] + c];
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i<n; i++)
            cin >> b[i];
        cout << solve(a, b, c, d)<<"\n";
    }

    return 0;
}