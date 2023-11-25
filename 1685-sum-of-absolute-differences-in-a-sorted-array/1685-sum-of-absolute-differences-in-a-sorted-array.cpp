class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int diffs = 0, n = nums.size();
        for(int i = 1; i < n; i++){
            diffs += nums[i] - nums[0];
        }
        vector<int> ans(n);
        ans[0] = diffs;
        for(int i = 1; i < n; i++){
            diffs += (i-1 - (n-1 - i)) * (nums[i] - nums[i-1]);
            ans[i] = diffs;
        }
        return ans;
    }
};