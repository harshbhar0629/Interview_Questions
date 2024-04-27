#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/submissions/1144415999/

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + k) % i;
        }
        return 1 + ans;
        queue<int>qu;
        for(int i=0; i<n; i++){
            qu.push(i+1);
        }

        while(qu.size() > 1){
            int x = k;
            while(x>1){
                qu.push(qu.front());
                qu.pop();
                x--;
            }
            qu.pop();
        }
        return qu.front();
    }
};

int main(){
    

    return 0;
}