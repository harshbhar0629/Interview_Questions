#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/integer-to-english-words/

class Solution
{

    vector<string> less_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> ten = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousand = {"", "Thousand", "Million", "Billion"};

    string helper(int num)
    {
        if (num == 0)
        {
            return "";
        }
        if (num < 20)
        {
            return less_20[num] + " ";
        }
        else if (num < 100)
        {
            return ten[num / 10] + " " + helper(num % 10);
        }
        else
        {
            return less_20[num / 100] + " Hundred " + helper(num % 100);
        }
    }

public:
    string numberToWords(int num)
    {
        if (num == 0)
        {
            return "Zero";
        }

        int i = 0;
        string words = "";

        while (num > 0)
        {
            if (num % 1000 != 0)
            {
                words = helper(num % 1000) + thousand[i] + " " + words;
            }
            num /= 1000;
            i++;
        }
        while (words.back() == ' ')
        {
            words.pop_back();
        }
        return words;
    }
};

int main(){
    

    return 0;
}