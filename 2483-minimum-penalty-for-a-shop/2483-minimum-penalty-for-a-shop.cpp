class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> suf(n+1);
        for(int i = n-1; i >= 0; i--){
            suf[i] = suf[i+1] + (customers[i] == 'Y');
        }
        int ans = n+1, ns = 0, min_pen = n+1;
        for(int i = 0; i <= n; i++){
            if(ns+suf[i] < min_pen){
                ans = i;
                min_pen = ns+suf[i];
            }
            ns += customers[i] == 'N';
        }
        return ans;
    }
};