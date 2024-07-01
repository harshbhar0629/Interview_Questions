#include <bits/stdc++.h>
using namespace std;

/**
 * company pay salary acc to one criteria 
 * hard task and easy task we can choose easy task any time but we can choose  hard task only if we can't doing any work on last day
 */
int dp[100005][5];
int f(int i, int last, vector<int>& easy, vector<int>& hard){
    if(i==easy.size()){
        return 0;
    }
    if(dp[i][last] != -1){
        return dp[i][last];
    }

    int skip = f(i + 1, 1, easy, hard);
    int esy = easy[i] + f(i + 1, 0, easy, hard);
    int hrd = 0;
    if(last == 1){
        hrd = hard[i] + f(i + 1, 0, easy, hard);
    }

    return dp[i][last] = max({skip, esy, hrd});
}

int fbu(vector<int>&easy, vector<int>& hard){
    memset(dp, 0, sizeof dp);
    int n = easy.size();

    for (int i = n - 1; i >= 0; i--){
        for (int last = 1; last >= 0; last--){
            int skip = dp[i + 1][1];
            int esy = easy[i] + dp[i + 1][0];
            int hrd = 0;
            if (last == 1){
                hrd = hard[i] + dp[i + 1][0];
            }

            dp[i][last] = max({skip, esy, hrd});
        }
    }

    return dp[0][0];
}

int main(){
    int n;
    cin >> n;
    vector<int> easy(n), hard(n);
    for (int i = 0; i<n; i++){
        cin >> easy[i] >> hard[i];
    }

    memset(dp, -1, sizeof dp);
    cout << f(0, 0, easy, hard) << "\n";
    cout << fbu(easy, hard)<<"\n";

    return 0;
}