#define ll long long
class Solution {
    // refer the excel sheet for expl
    map<pair<ll, ll>, ll> memo;
public:
    // ll dp(vector<ll>& nums, ll i, ll d){
    //     if(i == 0)
    //         return 0;
    //     if(memo.count({i,d}))
    //         return memo[{i,d}];
    //     ll curr = 0;
    //     for(ll j = 0; j < i; j++){
    //         memo[{i, nums[i]-nums[j]}] += (1 + dp(nums, j, nums[i] - nums[j]));
    //     }
    //     return memo[{i,d}] = curr;
    // }
    ll numberOfArithmeticSlices(vector<int>& nums) {
        ll n = nums.size();
        // ll ans = dp(nums, n-1, 0);
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < i; j++){
                ll currcd = 0LL + nums[i]-nums[j];
                memo[{i, currcd}] += (1 + memo[{j, currcd}]);
            }
        }
        ll ans =  0;
        for(auto &i: memo)
            ans += i.second;
        return ans - n*(n-1)/2;
    }
};