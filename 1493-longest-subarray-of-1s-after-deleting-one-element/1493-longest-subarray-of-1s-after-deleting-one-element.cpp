class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev = -1, curr = 0, n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1)
                curr++;
            else{
                if(prev != -1){
                    ans = max(ans, curr+prev);
                }
                prev = curr;
                curr = 0;
            }
            // cout<<nums[i]<<' '<<curr<<' '<<prev<<'\n';
        }
        if(nums.back() == 1 && prev != -1)
            ans = max(ans, curr+prev);
        if(prev == -1)
            return n-1;
        return ans;
    }
};