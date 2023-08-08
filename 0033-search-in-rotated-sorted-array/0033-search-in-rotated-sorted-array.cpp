class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1, mid;
        int end = -1;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            if(nums[mid] > nums.back()){
                lo = mid + 1;
                end = max(mid, end);
            }else{
                hi = mid - 1;
            }
        }
        if(end == -1)
            end = n-1;
        lo = end+1, hi = end+n;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            if(nums[mid%n] < target){
                lo = mid + 1;
            }else if(nums[mid%n] > target){
                hi = mid - 1;
            }else{
                return mid%n;
            }
        }
        // cout<<end;
        return -1;
    }
};