#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/run-length-encoding/1


/*You are required to complete this function */

string encode(string src){
    int n = src.size();
    int cnt = 0;
    char ch = src[0];
    string result = "";
    for (int i = 0; i < n; i++)
    {
        if (src[i] == ch)
        {
            cnt++;
        }
        else
        {
            result += ch + to_string(cnt);
            ch = src[i];
            cnt = 1;
        }
    }
    result += ch + to_string(cnt);
    return result;
}

// https : // leetcode.com/problems/string-compression/description/

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int ans = 0;
        for (int i = 0; i < n;)
        {
            char ch = chars[i];
            int cnt = 0;
            while (i < n and chars[i] == ch)
            {
                ++cnt;
                i++;
            }
            chars[ans++] = ch;
            if (cnt > 1)
            {
                for (auto it : to_string(cnt))
                {
                    chars[ans++] = it;
                }
            }
        }
        return ans;
    }
};

int main(){


    return 0;
}