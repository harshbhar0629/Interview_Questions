#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

/*
 * In approach-2 we can generate all possible subseq and then check it is found in dictionary and also apply sorting as well 
*/


/****************** Approach-1 *************************/
class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        string res = "";

        for (auto word : dictionary)
        {
            bool flag = false;
            int j = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (word[j] == s[i])
                {
                    j++;
                }
                if (j == word.size())
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                if (res.size() < word.size())
                {
                    res = word;
                }
                else if (res.size() == word.size() and res > word)
                {
                    res = word;
                }
            }
        }
        return res;
    }
};

int main(){
    

    return 0;
}