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
    void dp(TreeNode* root, int curr, int target, bool &flag){
        if(!root) return;
        curr += root->val;
        // if( ((root->left) || (root->right)) && curr == target)
        //     return;
        // if(curr > target) return;
        if(!(root->left) && !(root->right) && curr == target){
            flag = true;
            return;
        }
        dp(root->left, curr, target, flag);
        dp(root->right, curr, target, flag);
    }
    bool hasPathSum(TreeNode* root, int target) {
        if(!root) return false;
        bool flag = false;
        dp(root, 0, target, flag);
        return flag;
    }
};