#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{

    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(3, 1e9));

    dp[1][2] = a[1];
    dp[2][1] = dp[1][2] + a[2] + a[3];

    for (int i = 3; i <= n - 1; i++)
    {
        dp[i][2] = a[i] + min(dp[i - 2][1], dp[i - 2][2]);
        dp[i][1] = a[i + 1] + a[i] + dp[i - 1][2];
    }

    dp[n][2] = a[n] + min(dp[n - 2][1], dp[n - 2][2]);

    cout << min(dp[n][2], min(dp[n - 1][1], dp[n - 1][2]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
