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

//O(n) time and O(logn) space solution

//BST Iterator.. two pointer
class BSTIterator{ //has two forms of next.. one as next other as prev
    stack<TreeNode*> call;
    TreeNode* itr;
    bool fwd;
public:
    // unlike the original BSTIterator qsn, we only need to start from the root
    BSTIterator(TreeNode* root, bool fwd){itr = root; this->fwd = fwd; }
    int next(){
        while(itr || !call.empty()){
            if(itr){
                call.push(itr);
                itr = fwd ? itr->left : itr->right;
            }else{
                itr = call.top();
                call.pop();
                int ret = itr->val;
                itr = fwd ? itr->right : itr->left;
                return ret;
            }
        }
        return -1; //escape 
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        BSTIterator l(root, true), r(root, false);
        for(int i = l.next(), j = r.next(); i < j;){
            int sum = i + j;
            if(sum == k)
                return true;
            else if(sum < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};