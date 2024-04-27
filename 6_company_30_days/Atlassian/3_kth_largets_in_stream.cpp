#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest
{

    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->n = k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (pq.size() < k)
            {
                pq.push(nums[i]);
            }
            else if (pq.top() < nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val)
    {
        if (pq.size() < n)
        {
            pq.push(val);
        }
        else if (pq.top() < val)
        {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(){
    

    return 0;
}