class Solution {
    const int mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        vector<int> power(n);
        power[0] = 1;
        for(int i = 1; i < n; i++){
            power[i] = (2 * power[i-1]) % mod;
        }
        for(long long i = 0; i < n; i++){
            if(target - nums[i] >= nums[i]){
                auto u = upper_bound(nums.begin(), nums.end(), target-nums[i]);
                long long j = u - nums.begin() - 1;
                if(j >= i){
                    ans = (ans + power[j-i]%mod) % mod;
                }
            }
        }
        return ans;
    }
};