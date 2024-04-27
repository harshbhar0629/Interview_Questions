#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/gas-station/

int canCompleteCircuit(const vector<int> &A, const vector<int> &B){
    int idx = 0;
    int n = A.size();
    int availableGas = 0;
    int requiredGas = 0;
    int deficiency = 0;
    for (int i = 0; i < n; i++)
    {
        availableGas += A[i];
        requiredGas += B[i];
        if (requiredGas > availableGas)
        {
            deficiency += requiredGas - availableGas;
            availableGas = requiredGas = 0;
            idx = i + 1;
        }
    }
    if (deficiency + requiredGas <= availableGas)
    {
        return idx;
    }
    return -1;
}

int main(){
    

    return 0;
}