#include <bits/stdc++.h>
using namespace std;
//

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        int i = 0, t = k;

        while (t--)
        {
            ans.push_back(nums[i]);
            i++;
        }

        for (int j = k; j < n; j++)
        {
            int mini = min_element(ans.begin(), ans.end()) - ans.begin();
            if (ans[mini] < nums[j])
            {
                ans.erase(ans.begin() + mini);
                ans.push_back(nums[j]);
            }
        }

        return ans;
    }

    vector<int> maxSubsequence1(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<bool> present(n, true);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
            if (pq.size() > k)
            {
                int idx = pq.top().second;
                pq.pop();
                present[idx] = false;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (present[i] == true)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}