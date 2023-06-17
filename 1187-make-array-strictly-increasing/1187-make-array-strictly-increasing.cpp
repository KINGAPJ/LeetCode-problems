class Solution {
    vector<vector<int>> dp;
    vector<int> nums1, nums2;
public:
    //find the element just greater than the previous element in consideration and check using it
    int f(int i, int j){
        int m = nums2.size(), n = nums1.size();
        if(i == n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int prev = -1, curr = nums1[i];
        if(i > 0){
            if(j > 0)
                prev = nums2[j-1];
            else
                prev = nums1[i-1];
        }
        int smlGrThan = upper_bound(nums2.begin(), nums2.end(), prev) - nums2.begin();
        if(smlGrThan == m && prev >= curr)
            return 3001;
        int ans = 3001;
        if(smlGrThan < m && nums2[smlGrThan] != nums1[i])
            ans = min(ans, 1 + f(i+1, 1+smlGrThan));
        if(prev < curr){
            ans = min(ans, f(i+1, 0));
        }
        return dp[i][j] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        set<int> temp = set<int>(arr2.begin(), arr2.end());
        arr2 = vector<int>(temp.begin(), temp.end());
        int n = arr1.size(), m = arr2.size();
        dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
        nums1 = arr1, nums2 = arr2;
        int ans = f(0, 0);
        return ans >= 3001 ? -1 : ans;
    }
};