class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> pref(n+1);
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++)
            pref[i+1] = pref[i] + nums[i];
        for(auto &i: queries){
            int ind = upper_bound(pref.begin(), pref.end(), i) - pref.begin() - 1;
            ans.push_back(ind);
        }
        return ans;
    }
};