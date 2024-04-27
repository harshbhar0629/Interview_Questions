#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/trim-a-binary-search-tree/

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

class Solution
{

    TreeNode *trim(TreeNode *root, int lo, int hi)
    {
        if (root == NULL)
        {
            return NULL;
        }

        TreeNode *leftNode = trim(root->left, lo, hi);
        if (root->left != leftNode)
        {
            root->left = leftNode;
        }
        TreeNode *rightNode = trim(root->right, lo, hi);
        if (root->right != rightNode)
        {
            root->right = rightNode;
        }

        if (root->val < lo || root->val > hi)
        {
            return (root->left) ? root->left : root->right;
        }

        return root;
    }

    void f(TreeNode *root, int lo, int hi)
    {
        if (root == NULL)
        {
            return;
        }

        while (root->left)
        {
            if (root->left->val < lo)
            {
                root->left = root->left->right;
            }
            else if (root->left->val > hi)
            {
                root->left = root->left->left;
            }
            else
            {
                break;
            }
        }

        while (root->right)
        {
            if (root->right->val < lo)
            {
                root->right = root->right->right;
            }
            else if (root->right->val > hi)
            {
                root->right = root->right->left;
            }
            else
            {
                break;
            }
        }

        f(root->left, lo, hi);
        f(root->right, lo, hi);
    }

public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        // return trim(root, low, high);
        TreeNode *dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        f(dummy, low, high);
        return dummy->left;
    }
};

int main()
{

    return 0;
}