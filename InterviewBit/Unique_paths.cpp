#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int dp[105][105];
int f(int i, int j, const vector<vector<int>>& A){
    if(i == A.size() || j == A[0].size() || A[i][j] == 1){
        return 0;
    }
    if(i == A.size()-1 and j == A[0].size()-1){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int down = f(i+1, j, A);
    int right = f(i, j+1, A);
    
    return dp[i][j] = down + right;
}

int uniquePathsWithObstacles(vector<vector<int> > &A) {
    memset(dp, -1, sizeof dp);
    return f(0, 0, A);
}


int main(){
    

    return 0;
}