class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int n = obs.size();
        vector<int> vals(n, INT_MAX);
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int ind = upper_bound(vals.begin(), vals.end(), obs[i]) - vals.begin();
            vals[ind] = obs[i];
            ans[i] = ind + 1;
        }
        return ans;
    }
};