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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
        {
            return res;
        }
        stack<TreeNode *> s;
        TreeNode *ptr = root;
        while(!s.empty() || ptr != NULL)
        {
            if(ptr)
            {
                s.push(ptr);
                ptr = ptr->left;
            }
            else
            {
                TreeNode *node = s.top();
                s.pop();
                res.push_back(node->val);
                ptr = node->right;
            }
        }
        return res;

    }
};
