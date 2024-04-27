#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-collisions-on-a-road/description/

class Solution
{

    int f(string& dir){
        if(dir.size() == 0){
            return 0;
        }
        int cnt=0;
        stack<char>st;
        st.push(dir[0]);

        for(int i=1; i<dir.size(); i++){
            // 1st case of collision right and left
            if(!st.empty() and st.top() == 'R' and dir[i] == 'L'){
                cnt+=2;
                st.pop();
                st.push('S');
            }
            else if(!st.empty() and st.top() == 'S' and dir[i] == 'L'){
                cnt+=1;
            }
            else if(!st.empty() and st.top() == 'R' and dir[i] == 'S'){
                cnt+=1;
                st.pop();
                st.push('S');
            }
            else{
                st.push(dir[i]);
            }
        }

        while(!st.empty() and st.top() == 'R'){
            st.pop();
        }
        while(!st.empty()){
            if(st.top() == 'R') cnt++;
            st.pop();
        }

        return cnt;
    }

public:
    int countCollisions(string dir)
    {
        int left = 0;
        int cnt = 0;
        int n = dir.size();
        int right = n - 1;

        while (left < n and dir[left] == 'L')
        {
            left++;
        }

        while (right >= 0 and dir[right] == 'R')
        {
            right--;
        }

        for (int i = left; i <= right; i++)
        {
            if (dir[i] != 'S')
            {
                cnt++;
            }
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}
