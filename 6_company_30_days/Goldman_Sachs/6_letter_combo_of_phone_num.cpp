#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class solution{
    vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void f(int i, string &digits, string &s, vector<string>&res){
        if(i==digits.size()){
            res.push_back(s);
            return;
        }

        for(auto digit: keys[digits[i] - '0']){
            s.push_back(digit);
            f(i + 1, digits, s, res);
            s.pop_back();
        }
    }

public:

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        string s("");
        vector<string> res;
        f(0, digits, s, res);

        return res;
    }

};

int main(){

}