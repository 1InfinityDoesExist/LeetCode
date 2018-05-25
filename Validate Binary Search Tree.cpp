/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isBST(struct TreeNode *root, struct TreeNode *minNode, struct TreeNode *maxNode)
{
    if(root == NULL)
    {
        return true;
    }
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
    {
        return false;
    }
    return (isBST(root->left, minNode, root) && isBST(root->right, root, maxNode));
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        return isBST(root, NULL, NULL);
    }

};
