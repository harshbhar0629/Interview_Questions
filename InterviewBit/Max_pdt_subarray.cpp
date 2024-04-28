#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/max-product-subarray/

int maxProduct(const vector<int> &A)
{
    int n = A.size();
    int maxPdt = A[0];
    int mini = A[0], maxi = A[0];

    for (int i = 1; i < n; i++)
    {
        if (A[i] < 0)
        {
            swap(mini, maxi);
        }
        maxi = max(maxi * A[i], A[i]);
        mini = min(mini * A[i], A[i]);
        maxPdt = max(maxPdt, maxi);
    }

    return maxPdt;
}

int main(){
    

    return 0;
}