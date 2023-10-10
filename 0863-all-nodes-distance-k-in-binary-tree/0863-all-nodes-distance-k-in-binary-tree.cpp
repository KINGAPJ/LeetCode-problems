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
    vector<int> ans;
    bool found = false;
    void findNodes(TreeNode* root, int k){
        if(!root)
            return;
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        findNodes(root->left, k-1);
        findNodes(root->right, k-1);
    }
    void dfs(TreeNode* root, TreeNode* target, int &k){
        //k passed as reference for parents to pass it on to other subtree
        if(!root)
            return;
        if(root == target){
            found = true;
            findNodes(root, k);
            k--;
        }else{
            dfs(root->left, target, k);
            if(found){
                if(k > 0)
                    findNodes(root->right, k-1);
                else if(k == 0)
                    ans.push_back(root->val);
                k--;
                return;
            }
            dfs(root->right, target, k);
            if(found){
                if(k > 0)
                    findNodes(root->left, k-1);
                else if(k == 0)
                    ans.push_back(root->val);
                k--;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target, k);
        return ans;
    }
};