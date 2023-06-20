class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n, -1);
        long long curr = 0;
        for(int i = 0; i < n; i++){
            curr += nums[i];
            if(i >= 2*k){
                ret[i-k] = curr/(1+2*k);
                curr -= nums[i-2*k];
            }
        }
        return ret;
    }
};