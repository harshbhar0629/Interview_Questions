#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

//   Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(TreeNode *root, int &mx, int sum)
{
    if (!root)
    {
        return 0;
    }
    int x = solve(root->left, mx, sum);
    int y = solve(root->right, mx, sum);
    sum += max(x, y) + root->val;
    mx = max(mx, sum);
    mx = max(mx, y + x + root->val);
    if (sum < 0)
    {
        sum = 0;
    }
    return sum;
}
int maxPathSum(TreeNode *A)
{
    int mx = INT_MIN, sum = 0;
    solve(A, mx, sum);
    if (mx == 0)
    {
        return A->val;
    }
    return mx;
}

int main()
{

    return 0;
}