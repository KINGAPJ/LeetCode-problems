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
    int ans = 0;
public:
    void dfs(TreeNode* root, int curr, bool left){
        if(!root)
            return;
        ans = max(ans, curr);
        if(left){
            dfs(root->left, 1, true);
            dfs(root->right, curr+1, false);
        }else{
            dfs(root->left, curr+1, true);
            dfs(root->right, 1, false);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, 0, false);
        return ans;
    }
};