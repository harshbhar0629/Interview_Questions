#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/bulls-and-cows/

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int g[10] = {0};
        int s[10] = {0};
        int bulls = 0;
        int cows = 0;

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                int idx1 = secret[i] - '0';
                int idx2 = guess[i] - '0';
                s[idx1]++;
                g[idx2]++;
            }
        }

        for (int i = 0; i < 10; i++)
        {
            cows += min(g[i], s[i]);
        }

        string res = "";

        res += to_string(bulls);
        res += 'A';

        res += to_string(cows);
        res += 'B';

        return res;
    }
};

int main(){
    

    return 0;
}