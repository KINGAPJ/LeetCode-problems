class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lo = 0;
        for(int i = 0; i < nums.size(); i++){
            if((nums[i]&1) == 0)
                swap(nums[lo++], nums[i]);
        }
        return nums;
    }
};