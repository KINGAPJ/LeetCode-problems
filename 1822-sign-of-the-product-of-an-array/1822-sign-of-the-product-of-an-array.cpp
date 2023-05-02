class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(auto &i: nums){
            ans *= i;
            if(ans == 0)
                return 0;
            ans /= abs(ans);
        }
        return ans;
    }
};