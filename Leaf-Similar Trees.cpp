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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<struct TreeNode *> q1;
        stack<struct TreeNode *> q2;
        q1.push(root1);
        q2.push(root2);
        vector<int> r1;
        vector<int> r2;
       while(!q1.empty())
       {
           struct TreeNode *node1 = q1.top();
           q1.pop();
           if(node1->left == NULL && node1->right == NULL)
           {
               r1.push_back(node1->val);
           }
           if(node1->left)
           {
               q1.push(node1->left);
           }
           if(node1->right)
           {
               q1.push(node1->right);
           }
       }
        while(!q2.empty())
       {
           struct TreeNode *node2 = q2.top();
           q2.pop();
           if(node2->left == NULL && node2->right == NULL)
           {
               r2.push_back(node2->val);
           }
           if(node2->left)
           {
               q2.push(node2->left);
           }
           if(node2->right)
           {
               q2.push(node2->right);
           }
       }
        if(r1.size() != r2.size())
        {
            return false;
        }
        for(int iter = 0; iter < r1.size(); iter++)
        {
            if(r1[iter] != r2[iter])
            {
                return false;
            }
        }
        return true;


    }
};
