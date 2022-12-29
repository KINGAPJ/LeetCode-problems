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
    //T(n) = 2*T(n/2) + O(n)
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        auto maxi = max_element(nums.begin(), nums.end());
        vector<int> leftc(nums.begin(), maxi);
        vector<int> rightc(maxi+1, nums.end());
        TreeNode* left = constructMaximumBinaryTree(leftc);
        TreeNode* right = constructMaximumBinaryTree(rightc);
        TreeNode* root = new TreeNode(*maxi, left, right);
        return root;
    }
};