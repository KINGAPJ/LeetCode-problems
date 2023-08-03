class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), currk = 0, l = 0, ans = 0;
        for(int r = 0; r < n; r++){
            if(nums[r] == 0){
                if(currk < k)
                    currk++;
                else{
                    for(int x = l; x <= r; x++){
                        if(nums[x] == 0){
                            l = x+1;
                            break;
                        }
                    }
                }
            }
            // cout<<l<<' '<<r<<'\n';
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};