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
/*
    As a subtree you have two options:
    1. You give your best to your parent for further analysis on other subtrees. In this case,
        the path pauses at the root node 
    2. You return whatever maximum path there is within the subtree. In this case,
        the ends of the path are not at the root node.
        
    For option 1, we give two choices: 
            1. take any of the left or right subtrees + the root
            2. simply the root
    For option 2, we maintain a variable which will store the maximum for all kinds of paths
*/
public:
    int ans = (-1e3)-1;
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(!root->left && !root->right){
            ans = max(ans, root->val);
        }else if(!root->left){
            ans = max({ans, right, root->val, root->val + right, right + root->val});
        }else if(!root->right){
            ans = max({ans, left, root->val, root->val + left, left + root->val});
        }else{
            ans = max({ans, left, right, root->val, root->val + left, root->val + right, left + right + root->val});   
        }
        return root->val + max({0, left, right});
    }
    int maxPathSum(TreeNode* root) {
        int left = dfs(root->left);
        int right = dfs(root->right);
        return max({ans, root->val, left + root->val, right + root->val, left + right + root->val});
    }
};