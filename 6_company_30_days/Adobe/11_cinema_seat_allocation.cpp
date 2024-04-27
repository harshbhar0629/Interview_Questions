#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/cinema-seat-allocation/

class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {

        unordered_map<int, vector<int>> mp;
        for (auto seat : reservedSeats)
        {
            mp[seat[0]].push_back(seat[1]);
        }

        int len = mp.size();
        int cnt = 0;

        // O(n)
        for (auto &it : mp)
        {
            vector<int> v = it.second;
            int left = 1, middle = 1, right = 1;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] >= 2 and v[i] <= 5)
                {
                    left = 0;
                    if (v[i] == 4 || v[i] == 5)
                    {
                        middle = 0;
                    }
                }
                if (v[i] >= 6 and v[i] <= 9)
                {
                    right = 0;
                    if (v[i] == 6 || v[i] == 7)
                    {
                        middle = 0;
                    }
                }
            }
            // cout<<left<<" "<<middle<<" "<<right<<endl;
            cnt += max(middle, left + right);
        }
        // cout<<cnt;
        cnt += (n - len) * 2;

        return cnt;
    }
};

int main(){
    

    return 0;
}