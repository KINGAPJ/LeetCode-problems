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
    int ans = 0;
    void preorder(TreeNode* root, int maxx, int minn){
        ans = max(maxx-minn, ans);
        if(!root)
            return;
        preorder(root->left, max(maxx, root->val), min(minn, root->val));
        preorder(root->right, max(maxx, root->val), min(minn, root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        preorder(root, root->val, root->val);
        return ans;
    }
};