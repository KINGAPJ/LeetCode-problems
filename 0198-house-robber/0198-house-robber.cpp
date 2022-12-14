class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int dpp = nums[0], dp = max(nums[0], nums[1]), temp;
        for(int i = 2; i < n; i++){
            temp = dp;
            dp = max(dpp + nums[i], dp);
            dpp = temp;
        }
        return dp;
    }
};