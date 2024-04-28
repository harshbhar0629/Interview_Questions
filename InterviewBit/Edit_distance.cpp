#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/edit-distance/

int dp[500][500];
int editDis(const string& A, const string& B, int i, int j){
    if(i == A.size()){
        return B.size() - j;
    }
    if(j == B.size()){
        return A.size() - i;
    }
    if(dp[i][j] != -1) return dp[i][j];
        
    if(A[i] == B[j]){
        return dp[i][j] = editDis(A, B, i+1, j+1);
    }
    
    int insert = 1 + editDis(A, B, i, j+1);
    int del = 1 + editDis(A, B, i+1, j);
    int replace = 1 + editDis(A, B, i+1, j+1);
    
    return dp[i][j] = min({insert, del, replace});
}

 
int minDistance(string A, string B) {
    memset(dp, -1, sizeof dp);
    return editDis(A, B, 0, 0);
}


int main(){
    

    return 0;
}