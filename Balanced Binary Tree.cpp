/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(struct TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    queue<struct TreeNode *> q;
    q.push(root);
    int ht (0);
    while(1)
    {
        int nodeCount = q.size();
        if(nodeCount == 0)
        {
            return ht;
        }
        ht++;
        while(nodeCount--)
        {
            struct TreeNode *node = q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
    }
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {

        if(root == NULL)
        {
            return true;
        }
        int lh;
        int rh;
        lh = height(root->left);
        rh = height(root->right);
        if(abs(lh-rh) <= 1 && isBalanced(root->right) && isBalanced(root->left))
        {
            return true;
        }
        return false;
    }
};
