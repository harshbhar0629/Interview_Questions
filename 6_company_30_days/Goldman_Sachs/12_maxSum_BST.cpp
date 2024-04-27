#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class node
{
public:
    int maxSum, maxVal, minVal;
    node(int mini, int maxi, int sum)
    {
        this->maxSum = sum;
        this->minVal = mini;
        this->maxVal = maxi;
    }
};

class Solution
{

    node f(TreeNode *root, int &maxSum)
    {
        if (!root)
        {
            return node({INT_MAX, INT_MIN, 0});
        }

        auto left = f(root->left, maxSum);
        auto right = f(root->right, maxSum);
        int sum = 0;
        if (left.maxVal < root->val and root->val < right.minVal)
        {
            sum = root->val + left.maxSum + right.maxSum;
            maxSum = max(maxSum, sum);
            return node({min(left.minVal, root->val), max(root->val, right.maxVal), sum});
        }
        return node({INT_MIN, INT_MAX, 0});
    }

public:
    int maxSumBST(TreeNode *root)
    {
        int sum = 0;
        f(root, sum);
        return sum;
    }
};

int main()
{

    return 0;
}