class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        int lastpoint = p[0][1];
        int ans = 1;
        for(auto &i : p) {
            if(i[0] > lastpoint) {
                ans++;
                lastpoint = i[1];
            }
            lastpoint = min(i[1],lastpoint);
        }
        return ans;
    }
};