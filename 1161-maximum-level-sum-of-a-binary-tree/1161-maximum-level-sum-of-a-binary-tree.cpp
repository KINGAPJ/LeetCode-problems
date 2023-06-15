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
    int maxLevelSum(TreeNode* root) {
        int ans = -1, mini = INT_MIN, i = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size(), curr = 0;
            while(n--){
                auto u = q.front();
                q.pop();
                curr += u->val;
                if(u->left)
                    q.push(u->left);
                if(u->right)
                    q.push(u->right);
            }
            if(curr > mini){
                ans = i;
                mini = curr;
            }
            i++;
        }
        return ans;
    }
};