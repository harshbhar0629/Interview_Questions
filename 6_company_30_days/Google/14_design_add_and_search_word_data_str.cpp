#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary
{
    unordered_map<int, vector<string>> mp;

public:
    WordDictionary() {}

    void addWord(string word)
    {
        mp[word.size()].push_back(word);
    }

    bool search(string word)
    {
        for (auto str : mp[word.size()])
        {
            if (find(word, str))
            {
                return true;
            }
        }
        return false;
    }

private:
    bool find(string &s, string &t)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '.')
            {
                continue;
            }
            else if (s[i] != t[i])
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class Trie
{
public:
    bool isTerminal;
    Trie *child[26];
    Trie()
    {
        isTerminal = false;
        memset(child, NULL, sizeof(child));
    }
};
class WordDictionary
{
    Trie *root = new Trie();

public:
    WordDictionary() {}

    void addWord(string word)
    {
        Trie *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (curr->child[ch - 'a'] == NULL)
            {
                curr->child[ch - 'a'] = new Trie();
            }
            curr = curr->child[ch - 'a'];
        }
        curr->isTerminal = true;
    }

    bool search(string word)
    {
        return find(word, root);
    }

    bool find(string word, Trie *curr)
    {
        for (int i = 0; i < word.size() and curr; i++)
        {
            char ch = word[i];
            if (ch != '.')
            {
                curr = curr->child[ch - 'a'];
            }
            else
            {
                Trie *temp = curr;
                for (int j = 0; j < 26; j++)
                {
                    curr = temp->child[j];
                    if (find(word.substr(i + 1), curr))
                    {
                        return true;
                    }
                }
            }
        }
        if (curr != NULL)
        {
            return curr->isTerminal;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){
    

    return 0;
}