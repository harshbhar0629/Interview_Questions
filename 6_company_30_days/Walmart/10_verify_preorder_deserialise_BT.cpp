#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {

        /*** 2nd Approach ***/
        int n = preorder.size();
        int c = 1;

        for (int i = 0; i < n; i++)
        {
            c -= 1;
            if (c < 0)
                return false;
            if (preorder[i] != '#')
            {
                c += 2;
            }

            while (i < n and preorder[i] != ',')
            {
                i++;
            }
        }

        return c == 0;

        /***  1st Approach  ***/
        // stringstream ss(preorder);
        // string str;
        // int c=1;
        // while(getline(ss, str, ',')){
        //     c-=1;
        //     if(c<0) return false;
        //     if(str != "#"){
        //         c+=2;
        //     }
        // }

        // return c==0;
    }
};

int main(){
    

    return 0;
}