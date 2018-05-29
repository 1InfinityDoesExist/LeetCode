/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *helper(const vector<int> &nums, int low, int high)
{
    if(low > high)
    {
        return NULL;
    }
    int mid = (low+high)/2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = helper(nums, low, mid-1);
    node->right = helper(nums, mid+1, high);
    return node;
}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return NULL;
        }
        return helper(nums, 0, ((int)nums.size()-1));

    }
};
