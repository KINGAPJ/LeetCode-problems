class Solution {
public:
    int search(vector<int>& nums, int target) {
        int up = nums.size() - 1;
        int lo = 0;
        int mid = (up + lo)/2;
        do{
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid]){
                up = mid - 1;
                mid = (up + lo)/2;
            }
            else {
                lo = mid + 1;
                mid = (up+lo)/2;
            }
        } while(up >= lo);
        return -1;
    }
};