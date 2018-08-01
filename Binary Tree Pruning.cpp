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

    bool isValid(struct TreeNode *root)
    {
        if(root == NULL)
        {
            return true;
        }
        queue<struct TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            struct TreeNode *node = q.front();
            q.pop();
            if(node->val == 1)
            {
                return true;
            }
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root)
    {
        if(root == NULL)
        {
            return root;
        }
        queue<struct TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            struct TreeNode *node = q.front();
            q.pop();
            if(node->left && isValid(node->left))
            {
                q.push(node->left);
            }
            else
            {
                node->left = NULL;
            }
            if(node->right && isValid(node->right))
            {
                q.push(node->right);
            }
            else
            {
                node->right = NULL;
            }
        }
        return root;
    }
};
