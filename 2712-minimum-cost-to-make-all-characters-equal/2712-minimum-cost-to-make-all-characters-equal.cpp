#define ll long long
class Solution {
public:
    long long minimumCost(string s) {
        ll ans = 0, n = s.size();
        for(ll i = 1; i < n; i++){
            if(s[i] != s[i-1])
                ans += min(i, n-i);
        }
        return ans;
    }
};