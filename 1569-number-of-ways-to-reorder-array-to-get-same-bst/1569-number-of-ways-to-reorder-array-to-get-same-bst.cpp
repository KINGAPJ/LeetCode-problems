#define ll long long
class Solution {
    // refer dsa-cp
    int ncr[2001][1001];
    const int mod = 1e9 + 7;
public:
    ll dfsdp(vector<int>& nums){
        int n = nums.size();
        if(n <= 2)
            return 1;
        // to recursively find left and right subtrees:
        vector<int> left, right;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[0])
                right.push_back(nums[i]);
            else
                left.push_back(nums[i]);
        }
        ll left_res = dfsdp(left) % mod;
        ll right_res = dfsdp(right) % mod;
        ll fixed_leftright_permutations = ncr[left.size()+right.size()][left.size()];
        return (((fixed_leftright_permutations * left_res) % mod) * right_res) % mod;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        memset(ncr, 0, sizeof(ncr));
        ncr[0][0] = ncr[1][0] = ncr[1][1] = 1;
        for(int i = 2; i <= 2000; i++){
            ncr[i][0] = 1;
            for(int j = 1; j <= i && j <= 1000; j++){
                ncr[i][j] = (ncr[i-1][j] % mod + ncr[i-1][j-1] % mod) % mod;
            }
        }
        return dfsdp(nums) - 1;
    }
};
/*
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(x){val = x;}
};

class Solution {
    TreeNode* root;
public:
    void insert(TreeNode* node, int val){
        if(!node)
            return;
        if(val > node->val){
            if(!node->right)
                node->right = new TreeNode(val);
            else insert(node->right, val);
        }else{
            if(!node->left)
                node->left = new TreeNode(val);
            else insert(node->left, val);
        }
    }
    int numOfWays(vector<int>& nums) {
        root = new TreeNode(nums.begin());
        for(int i = 1; i < nums.size(); i++)
            insert(root, nums[i]);
        
    }
};
*/