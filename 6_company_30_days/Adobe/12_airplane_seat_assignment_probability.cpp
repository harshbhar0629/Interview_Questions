#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/airplane-seat-assignment-probability/description/

class Solution
{
public:
    double nthPersonGetsNthSeat(int n)
    {
        if (n == 1)
        {
            return 1.0;
        }
        if (n == 2)
        {
            return 0.5;
        }
        return (1.0 / n) + ((n - 2.0) / n) * nthPersonGetsNthSeat(n - 1);
        // return 0.5;
    }
};

int main(){
    

    return 0;
}