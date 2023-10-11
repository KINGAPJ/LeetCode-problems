class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int> start(n), last(n);
        for(int i = 0; i < n; i++){
            start[i] = flowers[i][0];
            last[i] = flowers[i][1]+1;
        }
        sort(start.begin(), start.end());
        sort(last.begin(), last.end());
        vector<int> ans;
        for(auto &i: people){
            int startInd = (upper_bound(start.begin(), start.end(), i) - start.begin());
            int endInd = (upper_bound(last.begin(), last.end(), i) - last.begin());
            ans.push_back(startInd - endInd);
        }
        return ans;
    }
};