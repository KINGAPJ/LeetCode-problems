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
    string first = "", last = "";
    bool firstfin = false;
    TreeNode* lca = nullptr;
    int findLCA(TreeNode* root, int st, int en){
        if(!root)
            return 0;
        int rt = 0;
        if(root->val == st || root->val == en)
            rt++;
        int l = findLCA(root->left, st, en);
        int r = findLCA(root->right, st, en);
        if(l+r+rt >= 2 && !lca){
            lca = root;
        }
        return l+r+rt;
    }
    bool src(TreeNode* root, int st, string &ans){
        if(!root)
            return false;
        bool left = src(root->left, st, ans);
        bool right = src(root->right, st, ans);
        if(root->val == st)
            return true;
        if(left || right){
            ans.push_back('U');
            return true;
        }
        return false;
    }
    bool dest(TreeNode* root, int en, string& ans){
        if(!root)
            return false;
        bool left = dest(root->left, en, ans);
        bool right = dest(root->right, en, ans);
        if(root->val == en)
            return true;
        if(left){
            ans.push_back('L');
            return true;
        }
        if(right){
            ans.push_back('R');
            return true;
        }
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        findLCA(root, startValue, destValue);
        string ans1 = "", ans2 = "";
        src(lca, startValue, ans1);
        dest(lca, destValue, ans2);
        reverse(ans2.begin(), ans2.end());
        return ans1+ans2;
    }
};