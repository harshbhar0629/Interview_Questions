#include <bits/stdc++.h>
using namespace std;

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
public:
    int maxLevelSum(TreeNode *root)
    {
        if (!root)
            return 0;
        int level = 1, l = 1;
        int maxSum = root->val;
        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty())
        {
            int sum = 0;
            for (int i = qu.size(); i > 0; i--)
            {
                auto curr = qu.front();
                qu.pop();
                sum += curr->val;
                if (curr->left)
                {
                    qu.push(curr->left);
                }
                if (curr->right)
                {
                    qu.push(curr->right);
                }
            }
            if (maxSum < sum)
            {
                maxSum = sum;
                level = l;
            }
            l++;
        }

        return level;
    }
};

int main()
{

    return 0;
}