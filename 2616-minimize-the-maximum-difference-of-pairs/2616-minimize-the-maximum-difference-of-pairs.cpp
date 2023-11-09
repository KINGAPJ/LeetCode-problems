class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int lo = 0, hi = 1e9+1, ans = hi, n = nums.size();
        if(n <= 1 || p == 0)
            return 0;
        sort(nums.begin(), nums.end());
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int i1 = 0, i2 = 1, pairs = 0;
            while(i1 < n && i2 < n){
                if(abs(nums[i2] - nums[i1]) <= mid){
                    pairs++;
                    i1 = i2+1;
                    i2 = i1+1;
                }else
                    i1++, i2++;
            }
            if(pairs >= p){
                hi = mid - 1;
                ans = min(ans, mid);
            }else
                lo = mid + 1;
        }
        return ans;
    }
};