class Solution {
public:
    int dp(int i, vector<int>& nums, int& bitmask, unordered_map<int, int>& memo){
        int n = nums.size();
        if(i == n)
            return 0;
        if(memo.count(bitmask))
            return memo[bitmask];
        int curr = 0;
        for(int j = 0; j < n; j++){
            if(!(bitmask & (1<<j))){
                for(int k = j+1; k < n; k++){
                    if(!(bitmask & (1<<k))){
                        bitmask ^= (1<<j);
                        bitmask ^= (1<<k);
                        curr = max(curr, 
                                   (i+1) * __gcd(nums[j], nums[k]) + dp(i+1, nums, bitmask, memo));
                        bitmask ^= (1<<j);
                        bitmask ^= (1<<k);
                    }
                }
            }
        }
        return memo[bitmask] = curr;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size(), bitmask = 0;
        // vector<int> memo(n, -1);
        unordered_map<int, int> memo;
        return dp(0, nums, bitmask, memo);
    }
};