#include <bits/stdc++.h>
using namespace std;
//

class Solution
{
public:
    string printMinNumberForPattern(string s)
    {
        int n = s.size();
        int num = 0;
        int last = 0;
        string res("");
        for (int i = 0; i <= n; i++)
        {
            num = i + 1;
            if (i == n || s[i] == 'I')
            {
                while (num > 0 and num > last)
                {
                    res += to_string(num);
                    num--;
                }
                last = i + 1;
            }
        }
        return res;
    }

    string printMinNumberForPattern1(string s)
    {
        int n = s.size();
        stack<int> st;
        string res("");
        for (int i = 0; i <= n; i++)
        {
            st.push(i + 1);
            if (i == n || s[i] == 'I')
            {
                while (st.empty())
                {
                    res += to_string(st.top());
                    st.pop();
                }
            }
        }
        return res;
    }
};

int main(){
    

    return 0;
}