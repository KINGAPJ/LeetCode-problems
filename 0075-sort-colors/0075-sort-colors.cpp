class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        for(int i = lo; i <= hi; i++){
            if(nums[i] == 0){
                swap(nums[lo++], nums[i]);
            }else if(nums[i] == 2){
                swap(nums[hi--], nums[i--]);
            }
        }
    }
};