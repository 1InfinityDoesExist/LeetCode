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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int> > res;
        if(root == NULL)
        {
            return res;
        }
        stack<struct TreeNode *> s1;
        stack<struct TreeNode *> s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            vector<int> temp1;
            int count1 (0);

            while(!s1.empty())
            {
                count1++;
                struct TreeNode *node1 = s1.top();
                s1.pop();
                temp1.push_back(node1->val);
                if(node1->left)
                {
                    s2.push(node1->left);
                }
                if(node1->right)
                {
                    s2.push(node1->right);
                }
            }
            if(count1 != 0)
            {
                res.push_back(temp1);
            }

            vector<int> temp2;
            int count2 (0);

            while(!s2.empty())
            {
                count2++;
                struct TreeNode *node2 = s2.top();
                s2.pop();
                temp2.push_back(node2->val);
                if(node2->right)
                {
                    s1.push(node2->right);
                }
                if(node2->left)
                {
                    s1.push(node2->left);
                }
            }
            if(count2 != 0)
            {
                res.push_back(temp2);
            }
        }
        return res;
    }
};
