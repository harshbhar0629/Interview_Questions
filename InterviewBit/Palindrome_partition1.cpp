#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/palindrome-partitioning/

bool isPalindrome(int i, int j, const string &A)
{
    while (i < j)
    {
        if (A[i] != A[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}

void f(int i, const string &A, vector<string> &res, vector<vector<string>> &ans)
{
    if (i >= A.size())
    {
        ans.push_back(res);
        return;
    }

    for (int j = i; j < A.size(); j++)
    {
        if (isPalindrome(i, j, A))
        {
            res.push_back(A.substr(i, j - i + 1));
            f(j + 1, A, res, ans);
            res.pop_back();
        }
    }
}

vector<vector<string>> partition(string A){
    vector<vector<string>> ans;
    vector<string> res;
    f(0, A, res, ans);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

int main(){
    

    return 0;
}