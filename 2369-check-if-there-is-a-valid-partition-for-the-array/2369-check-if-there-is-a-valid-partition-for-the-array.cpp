class Solution {
    vector<int> dp, arr;
    bool f(int i){
        int n = arr.size();
        if(i == n)
            return true;
        if(dp[i] != -1)
            return dp[i];
        bool ret = false;
        //case 1
        bool cases = false;
        if(i+1 < n && arr[i] == arr[i+1])
            cases = true;
        if(cases)
            ret |= f(i+2);
        cases = true;
        for(int j = i+1; j-i+1 <= 3; j++){
            if(j >= n || arr[j] != arr[i]){
                cases = false;
                break;
            }
        }
        if(cases)
            ret |= f(i+3);
        cases = true;
        for(int j = i+1; j-i+1 <= 3; j++){
            if(j >= n || arr[j]-arr[i] != j-i){
                cases = false;
                break;
            }
        }
        if(cases)
            ret |= f(i+3);
        return dp[i] = ret;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n, -1);
        arr = nums;
        return f(0);
    }
};
/*bool dp[3];
        memset(dp, 0, sizeof(dp));
        int n = nums.size();
        if(nums[n-1] == nums[n-2])
            dp[n-2] = true;
        if(n == 2)
            return dp[0];
        if(dp[n-2] && nums[n-2] == nums[n-3] || nums[n-3]+1 == nums[n-2] && nums[n-2]+1 == nums[n-1])
            dp[n-3] = true;
        if(n == 3)
            return dp[0];
        for(int i = n-4; i >= 0; i--){
            
        }*/