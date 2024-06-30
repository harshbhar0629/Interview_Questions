#include <bits/stdc++.h>
using namespace std;

/**
 * two type of oprn
 * 1. rotate it by left character with cost A means first character append to last of string
 * 2. change any character to any other character with the cost B
 */
int check(string s, string t){
    int cnt = 0;
    for (int i = 0; i < s.size(); i++){
        if(s[i]!=t[i])
            cnt++;
    }

    return cnt;
}

int solve(const string s, const string t, int a, int b){
    int cost = 1e9;
    const int n = s.size();
    for (int i = 0; i < n; i++){
        string newS = s.substr(i) + s.substr(0, i);
        int costA = i * a;
        int costB = check(newS, t)*b;
        cost = min(costA + costB, cost);
    }

    return cost;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        string s, t;
        cin >> s >> t;

        cout << solve(s, t, a, b);
    }

    return 0;
}