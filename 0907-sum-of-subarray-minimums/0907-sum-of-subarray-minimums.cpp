class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int, int>> mst;//{curr element, running sum}
        mst.push({0,0});
        int ans = 0;
        vector<int> pref_min_sum(n+1); //1-indexed
        for(int i = 0; i < n; i++){
            while(!mst.empty() && arr[i] < mst.top().first)
                mst.pop();
            int ind = mst.top().second;
          //pref_min_sum[i+1] = pref_min_sum[ind] + arr[i] * ((i+1) - ind);//actual expression
            pref_min_sum[i+1] = 
                ((((arr[i]%mod)*((i+1-ind)%mod))%mod)+(pref_min_sum[ind]%mod))%mod;
            while(pref_min_sum[i+1] < 0)
                pref_min_sum[i+1] += mod;
            mst.push({arr[i], i+1});
        }
        for(int i = 1; i <= n; i++){
            ans = (ans%mod + pref_min_sum[i])%mod;
            while(ans < 0)
                ans += mod;
        }
        return ans;
    }
};