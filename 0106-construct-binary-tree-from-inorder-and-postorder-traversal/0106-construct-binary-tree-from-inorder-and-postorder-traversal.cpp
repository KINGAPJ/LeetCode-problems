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
    unordered_map<int, int> findinorderind;
    TreeNode* build(vector<int>& in, vector<int>& po, int in_l, int in_r, int po_l, int po_r){
        if(in_l < 0 || in_r < 0 || po_l < 0 || po_r < 0 || in_l > in_r || po_l > po_r)
            return nullptr;
        if(in_l >= in.size() || in_r >= in.size() || po_l >= po.size() || po_r >= po.size())
            return nullptr;
        TreeNode* root = new TreeNode(po[po_r]);
        int rootval = po[po_r];
        int inorderroot = findinorderind[rootval];
        root->left = build(in, po, in_l, inorderroot-1, po_l, po_l + (inorderroot-in_l-1));
        root->right = build(in, po, inorderroot+1, in_r, po_l + (inorderroot-in_l), po_r-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            findinorderind[inorder[i]] = i;
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};