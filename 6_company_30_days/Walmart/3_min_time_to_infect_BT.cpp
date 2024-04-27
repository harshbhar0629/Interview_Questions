#include <bits/stdc++.h>
using namespace std;
// https : // leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10


//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

    TreeNode *createMapping(TreeNode *root, int start, unordered_map<TreeNode *, TreeNode *> &mp)
    {
        TreeNode *target;
        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty())
        {
            TreeNode *curr = qu.front();
            qu.pop();

            if (curr->val == start)
            {
                target = curr;
            }
            if (curr->left)
            {
                mp[curr->left] = curr;
                qu.push(curr->left);
            }
            if (curr->right)
            {
                mp[curr->right] = curr;
                qu.push(curr->right);
            }
        }

        return target;
    }

    int minTimeToInfected(unordered_map<TreeNode *, TreeNode *> &mp, TreeNode *target)
    {
        int time = 0;
        unordered_map<TreeNode *, int> vis;
        queue<TreeNode *> qu;
        vis[target] = 1;
        qu.push(target);

        while (!qu.empty())
        {
            int sz = qu.size();
            bool flag = false;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = qu.front();
                qu.pop();

                if (curr->left and !vis[curr->left])
                {
                    flag = true;
                    qu.push(curr->left);
                    vis[curr->left] = 1;
                }
                if (curr->right and !vis[curr->right])
                {
                    flag = true;
                    qu.push(curr->right);
                    vis[curr->right] = 1;
                }

                if (mp[curr] and !vis[mp[curr]])
                {
                    flag = true;
                    qu.push(mp[curr]);
                    vis[mp[curr]] = 1;
                }
            }

            if (flag){
                time++;
            }
        }

        return time;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        if (root == NULL)
            return 0;
        unordered_map<TreeNode *, TreeNode *> mp;
        // create mapping
        TreeNode *target = createMapping(root, start, mp);

        // starting from target node and infected all node by bfs traversal
        int time = minTimeToInfected(mp, target);

        return time;
    }
};

int main(){

    return 0;
}