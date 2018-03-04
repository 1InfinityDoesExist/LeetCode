/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isValidBS(struct TreeNode *root, struct TreeNode *minNode, struct TreeNode *maxNode)
{
    if(!root)
    {
        return true;
    }
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
    {
        return false;
    }
    return isValidBS(root->left, minNode, root) && isValidBS(root->right, root, maxNode);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBS(root, NULL, NULL);

    }
};

