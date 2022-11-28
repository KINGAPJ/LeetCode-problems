class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> zero, one, more;

        for (auto& match : matches) {
            int w = match[0], l = match[1];
            if (!(one.count(w)) &&
                !(more.count(w))) {
                zero.insert(w);
            }

            if (zero.count(l)) {
                zero.erase(l);
                one.insert(l);
            } else if (one.count(l)) {
                one.erase(l);
                more.insert(l);
            } else if (more.count(l)) {
                continue;
            } else {
                one.insert(l);
            }
        }

        vector<vector<int>> ans(2, vector<int>());
        ans[0].assign(zero.begin(), zero.end());
        ans[1].assign(one.begin(), one.end());
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};