/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {

        if(root == NULL)
        {
            return false;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return root->val == sum;
        }
        int remaining = sum - root->val;
        return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);

    }
};
