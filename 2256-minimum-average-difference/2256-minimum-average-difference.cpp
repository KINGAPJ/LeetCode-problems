class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n+1);
        for(int i = 1; i <= n; i++)
            pref[i] = pref[i-1] + nums[i-1];
        long long ans = INT_MAX, ind = n;
        for(int i = 0; i < n; i++){
            long long left = pref[i+1];
            long long right = pref.back() - left;
            left /= (i+1);
            right = (i == n-1) ? 0 : right/(n-i-1);
            // cout<<"l: "<<left<<" r: "<<right<<'\n';
            long long curr = abs(left - right);
            if(curr < ans){
                ans = curr;
                ind = i;
            }
        }
        return ind;
    }
};