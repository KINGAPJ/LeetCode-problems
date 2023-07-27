class Solution {
public:
    long long maxRunTime(int n, vector<int>& bt) {
        int k = bt.size();
        sort(bt.begin(), bt.end());
        if(n == k)
            return bt[0];
        long long extra_charge = 0;
        for(int i = 0; i < k-n; i++)
            extra_charge += bt[i];
        long long lo = 0, hi = 1e14, ans = 0;
        while(lo <= hi){
            long long time = lo + (hi - lo)/2;
            long long laptops = 0, extra = extra_charge;
            bool possible = true;
            for(int i = k-1; i >= k-n; i--){
                if(bt[i] + extra >= time){
                    laptops++;
                    if(bt[i] < time)
                        extra -= (time - bt[i]);
                }else{
                    possible = false;
                    break;
                }
            }
            if(possible){
                lo = time + 1;
                ans = max(ans, time);
            }else{
                hi = time - 1;
            }
        }
        return ans;
    }
};