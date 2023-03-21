#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll count = 0, n = nums.size();
        bool yes = false;
        ll strk = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                yes = true;
                strk++;
            }else{
                yes = false;
                count += (strk * (strk+1))/2;
                strk = 0;
            }
        }
        count += (strk * (strk+1))/2;
        return count;
    }
};