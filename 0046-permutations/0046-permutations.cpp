class Solution {
public:
    vector<vector<int>> v;
    void recurse(vector<int> &arr, vector <int> &nums, int len){
        int n = nums.size();
        if(n == len){
            v.push_back(arr);
            return;
        }
        for(int i = 0; i < n; i++){
            if(nums[i]!=15){
                int k = nums[i]; //the nums[i] has to stay pristine for the remainder of loop
                nums[i] = 15;
                arr[len] = k;
                recurse(arr, nums, len+1);
                nums[i] = k;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n =nums.size();
        vector<int>arr(n);
        recurse(arr, nums, 0);
        return v;
    }
};