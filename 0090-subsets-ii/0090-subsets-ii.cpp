class Solution {
    vector<vector<int>> ans;
    void f(int i, vector<int>& nums, vector<int>& curr){
        int n = nums.size();
        if(i == n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        f(i+1, nums, curr);
        curr.pop_back();
        int j = i+1;
        while(j < n && nums[i] == nums[j])
            j++;
        f(j, nums, curr);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        f(0, nums, curr);
        return ans;
    }
};