class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> sortedMins;
        int n = nums.size(), currMin = nums[k];
        sortedMins.push_back(currMin);
        for(int i = k+1; i < n; i++){
            currMin = min(currMin, nums[i]);
            sortedMins.push_back(currMin);
        }
        currMin = nums[k];
        for(int i = k-1; i >= 0; i--){
            currMin = min(currMin, nums[i]);
            sortedMins.push_back(currMin);
        }
        sort(sortedMins.begin(), sortedMins.end());
        int ans = nums[k];
        for(int i = 0; i < n; i++){ //size of sortedMins == n
            int numsLess = lower_bound(sortedMins.begin(), sortedMins.end(), 
                                       sortedMins[i]) - sortedMins.begin();
            int numsGreater = n - numsLess;
            ans = max(ans, numsGreater * sortedMins[i]);
        }
        return ans;
    }
};