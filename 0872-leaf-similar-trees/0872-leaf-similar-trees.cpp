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
    vector<int> one, two;
    void postorder(TreeNode* root, bool ot){
        if(!root)
            return;
        if(!root->left && !root->right){
            if(ot)
                one.push_back(root->val);
            else
                two.push_back(root->val);
            return;
        }
        postorder(root->left, ot);
        postorder(root->right, ot);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        postorder(root1, 1);
        postorder(root2, 0);
        return one == two;
    }
};