class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return {};
        vector<string> ans;
        string x = "";
        int strk = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]+1){
                strk++;
            }else{
                if(strk == 1){
                    x = to_string(nums[i-1]);
                    ans.push_back(x);
                }else{
                    x = to_string(nums[i-strk]);
                    x += "->";
                    x += to_string(nums[i-1]);
                    ans.push_back(x);
                }
                strk = 1;
                x = "";
            }
        }
        if(strk == 1){
            x = to_string(nums[n-1]);
            ans.push_back(x);
        }else{
            x = to_string(nums[n-strk]);
            x += "->";
            x += to_string(nums[n-1]);
            ans.push_back(x);
        }
        return ans;
    }
};