#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/

class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {

        vector<int> v, v1;
        int n = s.size();

        if (n < a.size() || n < b.size())
        {
            return {};
        }

        for (int i = 0; i < n - a.size() + 1; i++)
        {
            int j = i;
            if (s[j] == a[0])
            {
                bool flag = true;
                for (int k = 0; k < a.size(); k++)
                {
                    if (s[j] == a[k])
                    {
                        j++;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    v.push_back(i);
                }
            }
        }

        for (int i = 0; i < n - b.size() + 1; i++)
        {
            int j = i;
            if (s[j] == b[0])
            {
                bool flag = true;
                for (int k = 0; k < b.size(); k++)
                {
                    if (s[j] == b[k])
                    {
                        j++;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    v1.push_back(i);
                }
            }
        }

        vector<int> ans;

        int i = 0, j = 0;
        while (i < v.size() and j < v1.size())
        {
            if (abs(v[i] - v1[j]) <= k)
            {
                ans.push_back(v[i]);
                i++;
            }
            else
            {
                if (v[i] < v1[j])
                    i++;
                else
                    j++;
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}