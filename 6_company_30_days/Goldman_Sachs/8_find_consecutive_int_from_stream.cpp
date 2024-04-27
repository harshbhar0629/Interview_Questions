#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/

class Solution{
public:
    class DataStream
    {

        int cnt, val, k;

    public:
        DataStream(int value, int k)
        {
            this->val = value;
            this->k = k;
            cnt = 0;
        }

        bool consec(int num)
        {
            if (val == num)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }

            return cnt >= k;
        }
    };

    /**
     * Your DataStream object will be instantiated and called as such:
     * DataStream* obj = new DataStream(value, k);
     * bool param_1 = obj->consec(num);
     */

};

class DataStream1
{

    unordered_map<int, int> mp;
    deque<int> dq;
    int k, val;

public:
    DataStream1(int value, int k)
    {
        this->k = k;
        this->val = value;
        dq.clear();
        mp.clear();
    }

    bool consec(int num)
    {
        mp[num]++;
        dq.push_back(num);
        bool ans = (mp.size() == 1 and dq.size() == k and num == val);
        if (dq.size() >= k)
        {
            int fr = dq.front();
            dq.pop_front();
            if (--mp[fr] == 0)
            {
                mp.erase(fr);
            }
        }
        return ans;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

int main(){

}