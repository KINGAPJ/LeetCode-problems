class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& pt, long long cc) {
        int n = sp.size(), m = pt.size();
        vector<int> anss(n);
        sort(pt.begin(), pt.end());
        for(int i = 0; i < n; i++){
            int lo = 0, hi = m - 1, mid;
            int curr = sp[i];
            if((long long) pt[m-1] * curr < cc){
                anss[i] = 0;
                continue;
            }
            while(lo < hi){
                int mid = lo + (hi - lo)/2;
                if((long long) curr * pt[mid] >= cc){
                    hi = mid;
                }else if((long long) curr * pt[mid] < cc){
                    lo = mid + 1;
                }
            }
            anss[i] = m - lo;
        }
        return anss;
    }
};