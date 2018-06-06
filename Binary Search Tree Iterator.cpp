/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> res;
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(root == NULL)
        {
            return;
        }
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
                res.push_back(node->val);
                ptr = node->right;
            }
        }

    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(res.size() == 0)
        {
            return false;
        }
        return true;

    }

    /** @return the next smallest number */
    int next() {
        int ans = res.front();
        res.erase(res.begin());
        return ans;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
