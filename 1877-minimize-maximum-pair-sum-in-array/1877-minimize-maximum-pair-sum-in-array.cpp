class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums.front()+nums.back();
        for(int i = 1, n = nums.size(); i < n/2; i++)
            ans = max(ans, nums[i]+nums[n-1-i]);
        return ans;
    }
};