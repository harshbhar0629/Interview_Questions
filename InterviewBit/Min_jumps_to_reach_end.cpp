#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/min-jumps-array/

int jump(vector<int> &A) {
    int n = A.size();
    int curr = 0, jumps=0, farthest = 0;
    for(int i=0; i<n-1; i++){
        farthest = max(A[i]+i, farthest);
        if(curr == i){
            curr = farthest;
            jumps++;
        }
    }
    if(curr>=n-1) return jumps;
    return -1;
}


int main(){
    

    return 0;
}