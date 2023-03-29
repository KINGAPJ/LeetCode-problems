class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        if(sat.back() <= 0)
            return 0;
        int negpref = 0, pospref = 0;
        int posptr = lower_bound(sat.begin(), sat.end(), 0) - sat.begin();
        int negptr = posptr - 1;
        int ans = 0, n = sat.size(), pref = 0;
        for(int i = posptr; i < n; i++){
            ans += (i-posptr+1) * sat[i];
            pref += sat[i];
        }
        for(int i = negptr; i >= 0; i--){
            if(pref > -sat[i]){
                ans += pref + sat[i];
                pref += sat[i];
            }
        }
        return ans;
    }
};