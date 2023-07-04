class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int bits[32] = {0};
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < n; j++)
                bits[i] += ((nums[j] & (1<<i)) != 0);
        }
        for(int i = 0; i < 32; i++){
            if(bits[i]%3)
                ans |= (1<<i);
        }
        return ans;
    }
};