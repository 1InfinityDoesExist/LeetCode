/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int sum;

class Solution {
public:
    void solve(struct TreeNode *root, int cur)
    {
        cur = cur*10 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum = sum + cur;
        }
        if(root->left)
        {
            solve(root->left, cur);
        }
        if(root->right)
        {
            solve(root->right, cur);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return root->val;
        }
        sum = 0;
        solve(root, 0);
        return sum;
    }
};
