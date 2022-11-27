#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        vector<map<ll, int>> cnt(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ll d = (ll)nums[i] - (ll)nums[j];
                int sum = 0;
                if (cnt[j].find(d) != cnt[j].end()) {
                    sum = cnt[j][d];
                }
                cnt[i][d] += sum + 1;
                ans += sum;
            }
        }

        return (int)ans;
    }
};