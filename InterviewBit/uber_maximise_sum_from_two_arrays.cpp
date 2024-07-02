#include <bits/stdc++.h>
using namespace std;

/**
 * There are two arrays , 'B' and 'C' ; size of both the arrays is 'N' ;
 *  At each index you are supposed to pick up an element either from array 'C' or array 'B'
 * You have to maximise the final sum of all elements
 * condn: you can't pick 3 or more than 3 element from the same array
 * 
 * 1 <= N <= 10^5
 * 1<= b[i], c[i] <= 10^10
 */

#define ll long long int
ll dp[100005][5][5];

ll f(int i, int cntB, int cntC, vector<ll>& b, vector<ll>& c){
    if(i==b.size()){
        return 0;
    }
    if(dp[i][cntB][cntC] != -1){
        return dp[i][cntB][cntC];
    }

    ll pickB = 0, pickC = 0;
    if(cntB < 2){
        pickB = b[i] + f(i + 1, cntB + 1, 0, b, c);
    }
    if(cntC < 2){
        pickC = c[i] + f(i + 1, 0, cntC + 1, b, c);
    }

    return dp[i][cntB][cntC] = max(pickB, pickC);
}

int fbu(vector<ll>& b, vector<ll>& c){
    int n = c.size();
    memset(dp, 0, sizeof dp);

    for (int i = n - 1; i >= 0; i--){
        for (int cntB = 2; cntB >= 0; cntB--){
            for (int cntC = 2; cntC >= 0; cntC--){

                ll pickB = 0, pickC = 0;
                if (cntB < 2){
                    pickB = b[i] + dp[i + 1][cntB + 1][0];
                }

                if (cntC < 2){
                    pickC = c[i] + dp[i + 1][0][cntC + 1];
                }
                dp[i][cntB][cntC] = max(pickB, pickC);
            }
        }
    }

    return dp[0][0][0];
}

int main(){
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;

    vector<ll> b(n), c(n);
    for (int i = 0; i<n; i++){
        cin >> b[i];
        cin >> c[i];
    }

    cout << f(0, 0, 0, b, c) << "\n";
    cout << fbu(b, c) << "\n";

    return 0;
}