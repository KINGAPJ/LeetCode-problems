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
    vector<int> best;
    int bestFrq = 0, currFrq = 0, currElem = INT_MIN;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        if(root->val == currElem)
            currFrq++;
        else{
            if(currFrq > bestFrq){
                best.clear();
                best.push_back(currElem);
                bestFrq = currFrq;
            }else if(currFrq == bestFrq && currFrq != 0)
                best.push_back(currElem);
            currFrq = 1;
            currElem = root->val;
        }
        inorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        if(currFrq > bestFrq){
            best.clear();
            best.push_back(currElem);
            bestFrq = currFrq;
        }else if(currFrq == bestFrq && currFrq != 0)
            best.push_back(currElem);
        return best;
    }
};