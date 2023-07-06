class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, curr = 0, ans = n+1;
        for(; r < n; r++){
            curr += nums[r];
            if(curr >= target){
                while(l < n && curr - nums[l] >= target){
                    curr -= nums[l];
                    l++;
                }
                ans = min(ans, r-l+1);
            }
        }
        return ans == n+1 ? 0 : ans;
    }
};