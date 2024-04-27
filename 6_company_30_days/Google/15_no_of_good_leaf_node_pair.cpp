#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

    int ans = 0;
    vector<int> f(TreeNode *root, int d)
    {
        if (!root)
        {
            return {0};
        }
        if (!root->left and !root->right)
        {
            return {1};
        }

        auto left = f(root->left, d);
        auto right = f(root->right, d);

        for (auto l : left)
        {
            for (auto r : right)
            {
                if ((l != 0 and r != 0) and l + r <= d)
                {
                    ans++;
                }
            }
        }

        vector<int> res;

        for (auto l : left)
        {
            if (l + 1 < d and (l != 0))
            {
                res.push_back(l + 1);
            }
        }
        for (auto l : right)
        {
            if (l + 1 < d and (l != 0))
            {
                res.push_back(l + 1);
            }
        }
        return res;
    }

public:
    int countPairs(TreeNode *root, int distance)
    {
        f(root, distance);
        return ans;
    }
};

int main()
{

    return 0;
}