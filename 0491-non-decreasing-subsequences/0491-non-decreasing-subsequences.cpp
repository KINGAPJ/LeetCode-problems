class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int>& currSeq, vector<int>& nums, int ind){
        if(currSeq.size() >= 2)
            ans.push_back(currSeq);
        unordered_set<int> hash;
        for(int i = ind; i < nums.size(); i++){
            if((currSeq.empty() || nums[i] >= currSeq.back()) && !hash.count(nums[i])){
                currSeq.push_back(nums[i]);
                backtrack(ans, currSeq, nums, i + 1);
                currSeq.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currSeq;
        backtrack(ans, currSeq, nums, 0);
        return ans;
    }
};