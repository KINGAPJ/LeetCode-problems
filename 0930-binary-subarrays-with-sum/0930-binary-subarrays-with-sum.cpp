class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int iLo = 0, iHi = 0;
        int sumLo = 0, sumHi = 0;
        int ans = 0;

        for (int j = 0; j < nums.size(); ++j) {
            // While sumLo is too big, iLo++
            sumLo += nums[j];
            while (iLo < j && sumLo > goal)
                sumLo -= nums[iLo++];

            // While sumHi is too big, or equal and we can move, iHi++
            sumHi += nums[j];
            while (iHi < j && (sumHi > goal || sumHi == goal && nums[iHi] == 0))
                sumHi -= nums[iHi++];

            if (sumLo == goal)
                ans += iHi - iLo + 1;
        }

        return ans;
    }
};