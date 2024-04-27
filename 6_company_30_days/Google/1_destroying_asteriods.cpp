#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/destroying-asteroids/

#define ll long long int
class Solution
{
public:
    bool asteroidsDestroyed(ll mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        for (int i = 0; i < n; i++)
        {
            if (mass >= asteroids[i])
            {
                mass += asteroids[i];
            }
            else
                return false;
        }
        return true;
    }
};

int main(){
    

    return 0;
}