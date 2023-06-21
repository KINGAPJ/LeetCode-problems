class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long lo = INT_MAX, hi = 0, ans = LLONG_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            lo = min(lo, 0LL+nums[i]);
            hi = max(hi, 0LL+nums[i]);
        }
        while(lo <= hi){
            long long mid = lo + (hi - lo)/2;
            long long curr1 = 0, curr2 = 0;
            for(int i = 0; i < n; i++){
                curr1 += (abs(mid-nums[i]))*cost[i];
                curr2 += (abs(mid+1-nums[i]))*cost[i];
            }
            if(curr1 < curr2){
                hi = mid - 1;
                ans = min(curr1, ans);
            }else{
                lo = mid + 1;
                ans = min(curr2, ans);
            }
        }
        return ans;
    }
};