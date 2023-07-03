class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++){
            unordered_set<int> vis;
            vis.insert(nums[i]);
            int cur = 0;
            for(int j = i+1; j < n; j++){
                cur += vis.count(nums[j]) ? 0 : 1 - vis.count(nums[j]+1) - vis.count(nums[j]-1);
                vis.insert(nums[j]);
                ans += cur;
            }
        }
        return ans;
    }
};