/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> par;
    unordered_set<TreeNode*> vis;
    vector<int> res;
    void set_par(TreeNode* node, TreeNode* parent){
        if(!node)
            return;
        par[node] = parent;
        set_par(node->left, node);
        set_par(node->right, node);
    }
    void dfs(TreeNode* node, int k){
        if(!node)
            return;
        vis.insert(node);
        if(k == 0)
            res.push_back(node->val);
        if(node->left && !vis.count(node->left))
            dfs(node->left, k-1);
        if(node->right && !vis.count(node->right))
            dfs(node->right, k-1);
        if(par[node] && !vis.count(par[node]))
            dfs(par[node], k-1);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        set_par(root, nullptr);
        dfs(target, k);
        return res;
    }
};