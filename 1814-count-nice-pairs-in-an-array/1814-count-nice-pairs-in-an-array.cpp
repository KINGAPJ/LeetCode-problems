class Solution {
    const int mod = 1e9 + 7;
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long long> diffs;
        for(int i = 0; i < nums.size(); i++){
            string temp = to_string(nums[i]);
            reverse(temp.begin(), temp.end());
            diffs[stoi(temp) - nums[i]]++;
        }
        long long ans = 0;
        for(auto &i: diffs){
            ans = (ans + i.second*(i.second-1)/2) % mod;
        }
        return ans;
    }
};