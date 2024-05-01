#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/dungeon-princess/

int f(int i, int j, vector<vector<int>>& A, vector<vector<int>>& dp){
    if(i>=A.size() || j>=A[0].size()){
        return -1e8;
    }
    if(i == A.size()-1 and j == A[0].size()-1){
        return min(0, A[i][j]);
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = 0;
    ans = min(0, A[i][j] + max(f(i+1, j, A, dp), f(i, j+1, A, dp)));
    return dp[i][j] = ans;
}

int calculateMinimumHP(vector<vector<int> > &A) {
    vector<vector<int>>dp(A.size()+1, vector<int>(A[0].size()+1, -1));
    return abs(f(0, 0, A, dp)) + 1;
}


int main(){
    

    return 0;
}