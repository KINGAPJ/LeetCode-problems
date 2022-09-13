class Solution {
public:
    int summ = 0;
    int dp(vector<int>& nums, int i, int m/*, int last*/, vector<vector<int>>&memo){
        int n = nums.size();
        // cout<<i<<" "<<m<<endl;
        if(n-i == m){
            if(m == 0)
                return 0;
            return *max_element(nums.begin()+i, nums.end());
        }
        if(m == 0){
            return accumulate(nums.begin()+i, nums.end(), 0);
        }
        
        if(memo[i][m] != -1)
            return memo[i][m];
        int ans = 0;
        int minim = summ;
        for(int j = i; j < n; j++){
            ans += nums[j];
            minim = min(minim, max(ans, dp(nums, j+1, m-1, memo)));
        }
        return memo[i][m] = minim;
    }
    int splitArray(vector<int>& nums, int m) {
        // cout<<nums.size()<<" ";
        summ = accumulate(nums.begin(), nums.end(), 0);
        if(m == 1)
            return summ;
        vector<vector<int>> memo(((int) nums.size())+1, vector<int>(m+1, -1));
        return dp(nums, 0, m-1, memo);
    }
};