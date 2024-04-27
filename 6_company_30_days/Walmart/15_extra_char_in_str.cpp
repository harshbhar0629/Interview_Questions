#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/extra-characters-in-a-string/description/

/******************************* Approach-1 *****************************************/
class Solution
{
    int dp[55];
    int f(string &s, unordered_set<string> &s1, int i)
    {
        int n = s.size();
        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        int ans = f(s, s1, i + 1) + 1;
        string t = "";
        for (int j = i; j < n; j++)
        {
            t += s[j];
            if (s1.count(t) > 0)
            {
                ans = min(ans, f(s, s1, j + 1));
            }
        }
        return dp[i] = ans;
    }

public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_set<string> s1(dictionary.begin(), dictionary.end());
        memset(dp, -1, sizeof dp);
        return f(s, s1, 0);
    }
};

/******************************* Approach-2 *****************************************/

class Trie
{
public:
    char data;
    bool isTerminal;
    unordered_map<char, Trie *> child;
    Trie(char data)
    {
        this->data = data;
        this->isTerminal = false;
    }

    void insert(string &word, Trie *head)
    {
        Trie *curr = head;
        for (auto ch : word)
        {
            if (curr->child.count(ch))
            {
                curr = curr->child[ch];
            }
            else
            {
                Trie *newChild = new Trie(ch);
                curr->child[ch] = newChild;
                curr = newChild;
            }
        }
        curr->isTerminal = true;
    }
};

class Solution
{
    int dp[55];

public:
    int minExtraChar(string s, vector<string> &dictionary)
    {

        Trie *head = new Trie('\0');
        for (auto word : dictionary)
        {
            head->insert(word, head);
        }

        int n = s.size();
        memset(dp, -1, sizeof dp);

        function<int(int)> f = [&](int i)
        {
            if (i >= n)
            {
                return 0;
            }
            if (dp[i] != -1)
            {
                return dp[i];
            }

            int ans = 1 + f(i + 1);
            Trie *curr = head;

            for (int j = i; j < n; j++)
            {
                char ch = s[j];
                if (curr->child.count(ch) == 0)
                {
                    break;
                }
                curr = curr->child[ch];
                if (curr->isTerminal)
                {
                    ans = min(ans, f(j + 1));
                }
            }
            return dp[i] = ans;
        };

        return f(0);
    }
};

int main(){
    

    return 0;
}