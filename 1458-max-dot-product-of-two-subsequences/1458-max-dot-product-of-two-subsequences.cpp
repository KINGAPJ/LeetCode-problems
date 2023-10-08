class Solution {
    vector<int> nums1, nums2;
    vector<vector<int>> dp;
    int f(int i, int j){
        int n1 = nums1.size(), n2 = nums2.size();
        if(i == n1 || j == n2)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int opt1 = f(i+1, j); // not multiply
        int opt2 = f(i, j+1); // not multiply again
        int opt3 = nums1[i]*nums2[j] + f(i+1, j+1);
        int ans = max({opt1, opt2, opt3});
        return dp[i][j] = ans;
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        int n1 = nums1.size(), n2 = nums2.size();
        dp = vector(n1+1, vector<int>(n2+1, -1));
        int ans = f(0, 0);
        if(ans > 0)
            return ans;
        int sml1 = INT_MAX, sml2 = INT_MAX, grt1 = INT_MIN, grt2 = INT_MIN;
        sml1 = *min_element(nums1.begin(), nums1.end());
        sml2 = *min_element(nums2.begin(), nums2.end());
        grt1 = *max_element(nums1.begin(), nums1.end());
        grt2 = *max_element(nums2.begin(), nums2.end());
        return max({sml1*grt2, grt1*sml2, sml1*sml2, grt1*grt2});
    }
};