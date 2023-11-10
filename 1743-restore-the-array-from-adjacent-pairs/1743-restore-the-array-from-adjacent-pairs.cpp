class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjPairs) {
        int n = adjPairs.size();
        unordered_map<int, vector<int>> nbrs;
        for(int i = 0; i < n; i++){
            nbrs[adjPairs[i][0]].push_back(adjPairs[i][1]);
            nbrs[adjPairs[i][1]].push_back(adjPairs[i][0]);
        }
        int head = INT_MAX;
        vector<int> nums;
        for(auto x: nbrs){
            if(x.second.size() == 1){
                head = x.first;
                break;
            }
        }
        nums.push_back(head);
        nums.push_back(nbrs[head][0]);
        while (nums.size() < n+1) {
            auto tail = nums.back(), prev = nums[nums.size() - 2];
            auto &next = nbrs[tail];
            if (next[0] != prev)
                nums.push_back(next[0]);
            else
                nums.push_back(next[1]);
        }
        return nums;
    }
};