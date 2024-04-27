#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/construct-the-longest-new-string/

class Solution
{

    int f(int x, int y, int z, char ch){
        if(x==0 and y==0 and z==0){
            return 0;
        }
        int res = 0;

        if(x>0 and ch != 'A'){
            res = max(res, 2+ f(x-1, y, z, 'A'));
        }
        if(y>0 and ch != 'B'){
            res = max(res, 2+ f(x, y-1, z, 'B'));
        }
        if(z>0){
            res = max(res, 2+ f(x, y, z-1, 'B'));
        }

        return res;
    }

    // char ch = 'A';
    // 'A' - 'A' = 0;
    // 'B' - 'A' = 1;
    int dp[52][52][52][3];
    int f(int x, int y, int z, int last){
        if(x==0 and y==0 and z==0){
            return 0;
        }
        if(dp[x][y][z][last] != -1){
            return dp[x][y][z][last];
        }

        int res = 0;
        if(x>0 and last != 0){
            res = max(res, 2+ f(x-1, y, z, 0));
        }
        if(y>0 and last != 1){
            res = max(res, 2+ f(x, y-1, z, 1));
        }
        if(z>0 and last != 0){
            res = max(res, 2+ f(x, y, z-1, 1));
        }

        return dp[x][y][z][last] = res;
    }

public:
    int longestString(int x, int y, int z)
    {
        // return f(x, y, z, 'Z');
        // memset(dp, -1, sizeof dp);
        // return f(x, y, z, 2);

        int ans = 0;
        ans += (x < y) ? 4 * x : y * 4;
        ans += 2 * z;

        if (x != y)
        {
            ans += 2;
        }

        return ans;
    }
};

int main(){
    

    return 0;
}