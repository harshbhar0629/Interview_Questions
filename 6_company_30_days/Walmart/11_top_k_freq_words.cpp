#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/top-k-frequent-words/


/**************************  1st-Approach   **************************************/
// TC: O(nlogn + n*(2*n))
class Solution
{

    static bool cmp(pair<int, string> &a, pair<int, string> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    }

public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        int n = words.size();
        vector<pair<int, string>> v(n, pair<int, string>(0, ""));

        for (int i = 0; i < n; i++)
        {
            int occur = 0;
            for (int j = 0; j < n; j++)
            {
                if (words[i] == words[j])
                {
                    occur++;
                }
            }
            int idx = 0;
            for (int k = 0; k < n; k++)
            {
                if (words[i] == words[k])
                {
                    idx = k;
                    break;
                }
            }
            v[idx].first = occur;
            v[idx].second = words[i];
        }

        vector<string> res;
        sort(v.begin(), v.end(), cmp);
        int i = 0;
        while (k--)
        {
            res.push_back(v[i].second);
            i++;
        }
        return res;
    }
};


/*********************************  2nd-Approach  ******************************************/
// TC: O(nlogK) + SC:O(N)
class cmp
{
public:
    bool operator()(pair<int, string> &a, pair<int, string> &b) const
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        unordered_map<string, int> mp;
        for (auto word : words)
        {
            mp[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<string> res(k);
        while (k--)
        {
            res[k] = pq.top().second;
            pq.pop();
        }

        return res;
    }
};

/******************************* 3rd-Approach *******************************************/
// 
class cmp
{
public:
    bool operator()(pair<int, string> a, pair<int, string> b) const
    {
        if (a.first < b.first)
            return true; // it will check freq of string who has greater freq will enjoy
        else if (a.first == b.first and a.second > b.second)
            return true; // second check if string lexographically max. if greater then true else false
        return false;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        unordered_map<string, int> mp;
        for (auto str : words)
        {
            mp[str]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        vector<string> ans;
        while (k-- and pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

int main(){
    

    return 0;
}