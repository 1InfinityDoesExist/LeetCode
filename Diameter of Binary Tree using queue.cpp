/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int max(int x, int y)
{
    return x > y ? x : y;
}

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
        int sz = q.size();
        if(sz == 0)
        {
            return ht;
        }
        ht++;
        while(sz--)
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        int ldiameter = diameterOfBinaryTree(root->left);
        int rdiameter = diameterOfBinaryTree(root->right);

        return max((lh+rh), max(ldiameter, rdiameter));
    }
};
