/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, vector<int> &nums, int t){
        // if(t < 0)
        //     return;
        nums.push_back(root->val);
        t -= root->val;
        if(!root->left && !root->right && t == 0){
            ans.push_back(nums);
            nums.pop_back();
            return;
        }
        if(root->left)
            dfs(root->left, nums, t);
        if(root->right)
            dfs(root->right, nums, t);
        nums.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        vector<int> nums;
        dfs(root, nums, targetSum);
        return ans;
    }
};