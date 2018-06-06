/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void bst(struct TreeNode *root, vector<int> &A)
{
    if(root == NULL)
    {
        return;
    }
    bst(root->left, A);
    root->val = A.front();
    A.erase(A.begin());
    bst(root->right, A);
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL)
        {
            return;
        }
        vector<int> ans;
        stack<struct TreeNode *> s;
        struct TreeNode *ptr = root;
        while(!s.empty() || ptr)
        {
            if(ptr)
            {
                s.push(ptr);
                ptr = ptr->left;
            }
            else
            {
                struct TreeNode *node = s.top();
                s.pop();
                ans.push_back(node->val);
                ptr = node->right;
            }
        }
        sort(ans.begin(), ans.end());
        bst(root, ans);
    }
};
