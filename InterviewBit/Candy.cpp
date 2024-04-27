#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/distribute-candy/

int candy(vector<int> &A){
    int n = A.size();
    vector<int> distributeCandy(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (A[i - 1] < A[i])
        {
            // handling the case when it's left neighbour having less rating then the ith person having more candies
            distributeCandy[i] = distributeCandy[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] > A[i + 1])
        {
            // handling the case when it's right neighbour having less rating then the ith person having more candies
            distributeCandy[i] = max(distributeCandy[i], 1 + distributeCandy[i + 1]);
        }
    }

    int totalCandy = 0;
    for (int i = 0; i < n; i++)
    {
        totalCandy += distributeCandy[i];
    }
    return totalCandy;
}

int main(){
    

    return 0;
}