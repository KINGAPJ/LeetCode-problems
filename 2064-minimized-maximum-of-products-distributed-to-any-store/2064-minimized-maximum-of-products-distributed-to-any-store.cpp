class Solution {
public:
    int minimizedMaximum(int n, vector<int>& qts) {
        long long hi = accumulate(qts.begin(), qts.end(), 0LL);
        long long lo = 1, ans = hi, sz = qts.size();
        while(lo <= hi){
            long long mid = lo + (hi - lo)/2;
            long long i = 0;
            for(int j = 0; j < sz; j++){
                i += qts[j]/mid;
                i += (qts[j] % mid) != 0;
            }
            if(i > n){
                lo = mid + 1;
            }else{
                ans = min(mid, ans);
                hi = mid - 1;
            }
        }
        return ans;
    }
};