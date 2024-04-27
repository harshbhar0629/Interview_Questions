#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

class Solution
{

    bool isPal(string &s)
    {
        if (s.size() <= 1)
            return true;
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }

    void f(string &s, string &t1, string &t2, int i, int &ans)
    {
        if (i >= s.size())
        {

            if (isPal(t1) and isPal(t2))
            {
                int size = t1.size() * t2.size();
                ans = max(ans, size);
            }
            return;
        }

        f(s, t1, t2, i + 1, ans);

        // pick in string 1
        t1.push_back(s[i]);
        f(s, t1, t2, i + 1, ans);
        t1.pop_back();

        // pick in string 2
        t2.push_back(s[i]);
        f(s, t1, t2, i + 1, ans);
        t2.pop_back();
    }

public:
    int maxProduct(string s)
    {
        int ans = 0;
        string s1 = "", s2 = "";
        f(s, s1, s2, 0, ans);

        return ans;
    }
};

int main(){
    

    return 0;
}