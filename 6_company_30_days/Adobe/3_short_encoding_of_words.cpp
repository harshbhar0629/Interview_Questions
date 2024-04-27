#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/short-encoding-of-words/description/

/******************************** Approach-1 ******************************/
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {

        set<string>s1(words.begin(), words.end());
        
        // TC: O(n*m*m) => o(n*m^2)
        for(auto word: words){
            for(int i=1; i<word.size(); i++){
                s1.erase(word.substr(i));
            }
        }

        int cnt=0;
        for(auto s: s1){
            cnt+=s.size() + 1;
        }  

        return cnt;
    }
};

/******************************** Approach-2 ******************************/

class Trie
{
public:
    char data;
    unordered_map<char, Trie *> child;
    Trie(char data)
    {
        this->data = data;
    }

    bool searchWord(string &word, Trie *head)
    {
        bool flag = false;
        Trie *curr = head;
        for (int i = word.size() - 1; i >= 0; i--)
        {
            char ch = word[i];
            if (curr->child.count(ch))
            {
                curr = curr->child[ch];
            }
            else
            {
                flag = true;
                Trie *newChild = new Trie(ch);
                curr->child[ch] = newChild;
                curr = newChild;
            }
        }

        return flag;
    }
};

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {

        sort(words.begin(), words.end(), [&](string &a, string &b)
             { return a.size() > b.size(); });

        int cnt = 0;
        Trie *head = new Trie('\0');
        for (auto word : words)
        {
            if (head->searchWord(word, head))
            {
                cnt += word.size() + 1;
            }
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}