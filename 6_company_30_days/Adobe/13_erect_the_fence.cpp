#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/erect-the-fence/description/

class Solution
{
    /**
     * we have to find the slope every time
     * m12 = (y2-y1)/(x2-x1)
     * m23 = (y3-y2)/(x3-x2)
     * (m23 - m12) > 0
     * Take LCM
     * LOWER: (y3-y2)(x2 - x1) - (y2-y1)(x3-x2) > 0
     * UPPER: (y3-y2)(x2 - x1) - (y2-y1)(x3-x2) < 0
     **/

    int find_eqn_value(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> p3)
    {
        int x1 = p1.first;
        int x2 = p2.first;
        int x3 = p3.first;

        int y1 = p1.second;
        int y2 = p2.second;
        int y3 = p3.second;

        return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {

        deque<pair<int, int>> lower, upper;
        sort(trees.begin(), trees.end());

        for (auto point : trees)
        {
            int l = lower.size();
            int u = upper.size();

            while (l >= 2 and find_eqn_value(lower[l - 2], lower[l - 1], {point[0], point[1]}) < 0)
            {
                l--;
                lower.pop_back();
            }

            while (u >= 2 and find_eqn_value(upper[u - 2], upper[u - 1], {point[0], point[1]}) > 0)
            {
                u--;
                upper.pop_back();
            }

            lower.push_back({point[0], point[1]});
            upper.push_back({point[0], point[1]});
        }

        set<pair<int, int>> st;
        vector<vector<int>> res;

        for (auto point : lower)
        {
            st.insert(point);
        }

        for (auto point : upper)
        {
            st.insert(point);
        }

        for (auto it : st)
        {
            res.push_back({it.first, it.second});
        }

        return res;
    }
};

int main(){
    

    return 0;
}