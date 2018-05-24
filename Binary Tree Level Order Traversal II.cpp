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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL)
        {
            return res;
        }

        queue<struct TreeNode *> q1;
        queue<struct TreeNode *> q2;

        q1.push(root);
        while(!q1.empty() || !q2.empty())
        {
            vector<int> temp1;
            int count1 (0);
            while(!q1.empty())
            {
                count1++;
                struct TreeNode *node1 = q1.front();
                q1.pop();
                temp1.push_back(node1->val);
                if(node1->left)
                {
                    q2.push(node1->left);
                }
                if(node1->right)
                {
                    q2.push(node1->right);
                }
            }
            if(count1 != 0)
            {
                res.push_back(temp1);
            }


            vector<int> temp2;
            int count2 (0);
            while(!q2.empty())
            {
                count2++;
                struct TreeNode *node2 = q2.front();
                q2.pop();
                temp2.push_back(node2->val);
                if(node2->left)
                {
                    q1.push(node2->left);
                }
                if(node2->right)
                {
                    q1.push(node2->right);
                }
            }
            if(count2 != 0)
            {
                res.push_back(temp2);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
