#define ll long long
class Solution {
    // refer the excel sheet for expl
    map<pair<ll, ll>, ll> memo;
public:
    ll numberOfArithmeticSlices(vector<int>& nums) {
        ll n = nums.size();
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