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
    bool singleodd(int num){
        int cnt = 0;
        for(int i = 0; i < 10; i++)
            if(num & (1 << i))
                cnt++;
        return cnt <= 1;
    }
    int dfs(TreeNode* root, int bit){
        bit ^= (1<<root->val);
        if(!root->left && !root->right){
            // cout<<bit<<' ';
            return singleodd(bit);
        }
        int cnt = 0;
        if(root->left)
            cnt += dfs(root->left, bit);
        if(root->right)
            cnt += dfs(root->right, bit);
        return cnt;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0); // /2 because it gets evaluated twice for each leaf
    }
};