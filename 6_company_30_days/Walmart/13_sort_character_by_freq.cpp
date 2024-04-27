#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (auto ch : s)
        {
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        string result = "";

        while (!pq.empty())
        {
            // no. of time and character
            result.append(pq.top().first, pq.top().second);
            pq.pop();

            // int cnt = pq.top().first;
            // char ch = pq.top().second;
            // while(cnt--){
            //     result+=ch;
            // }
        }

        return result;
    }
};

/********************************* TLE *********************************/
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.size();
        vector<int> upper(26, 0), lower(26, 0), digit(10, 0);

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (ch == s[j])
                {
                    cnt++;
                }
            }
            if (ch >= 'a' and ch <= 'z')
            {
                int idx = ch - 'a';
                lower[idx] = cnt;
            }
            if (ch >= 'A' and ch <= 'Z')
            {
                int idx = ch - 'A';
                upper[idx] = cnt;
            }
            if (ch >= '0' and ch <= '9')
            {
                int idx = ch - '0';
                digit[idx] = cnt;
            }
        }

        vector<pair<int, char>> v;
        for (int i = 0; i < 26; i++)
        {
            if (lower[i] > 0)
            {
                v.push_back({lower[i], i + 'a'});
            }
            if (upper[i] > 0)
            {
                v.push_back({upper[i], i + 'A'});
            }
            if (i <= 9 and digit[i] > 0)
            {
                v.push_back({digit[i], i + '0'});
            }
        }

        sort(v.begin(), v.end());

        s = "";
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int cnt = v[i].first;
            char ch = v[i].second;

            while (cnt--)
            {
                s += ch;
            }
        }
        return s;
    }
};

int main(){
    

    return 0;
}