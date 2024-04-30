#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/ways-to-decode/

const int MOD = 1e9 + 7;
int dp[100005];
int f(int i, const string &A)
{
    // actually we don't have to generate all strings or i would say sub-strings but at every moment we have to check is it possible to make character or not
    if (i >= A.size() || A[i] == '0')
    {
        return 0;
    }
    if (i == A.size() - 1)
    {
        return A[i] != '0';
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    if (i == A.size() - 2)
    {
        bool canMakeCharacter = stoi(A.substr(i, 2)) <= 26;
        return dp[i] = (canMakeCharacter + f(i + 1, A)) % MOD;
    }

    // if substr(i, 2)<=26 means we can make character of size 2 so make ans from (i+2 .. n) and also add next iteration answer (i+1..n)
    bool canMakeCharacter = stoi(A.substr(i, 2)) <= 26;
    return dp[i] = ((canMakeCharacter ? f(i + 2, A) % MOD : 0) % MOD + f(i + 1, A)) % MOD;
}

int numDecodings(string A)
{
    memset(dp, -1, sizeof dp);
    return f(0, A);
}

int main(){
    

    return 0;
}