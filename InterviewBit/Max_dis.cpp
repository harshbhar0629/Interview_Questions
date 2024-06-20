#include <bits/stdc++.h>
using namespace std;

int maxDiff(vector<int> &a, int n)
{
    vector<int> right_max(n);
    right_max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], a[i]);
    }

    int maxi = 0;
    int i = 0, j = 0;
    while (i < n and j < n)
    {
        if (right_max[j] >= a[i])
        {
            maxi = max(maxi, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return maxi;
}

int main(){
    

    return 0;
}