class Solution {
    void f(vector<int> &rods, int i, int sum1, int sum2, int n, unordered_map<int, int> &mp){
        if(i == n){
            mp[sum1-sum2] = max(mp[sum1-sum2], sum1);
            return;
        }
        f(rods, i+1, sum1+rods[i], sum2, n, mp);
        f(rods, i+1, sum1, sum2+rods[i], n, mp);
        f(rods, i+1, sum1, sum2, n, mp);
    }
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> half1, half2;
        int n = rods.size();
        f(rods, 0, 0, 0, n/2, half1);
        // cout<<'\n';
        f(rods, n/2, 0, 0, n, half2);
        int ans = 0;
        // for(auto &i: half1){
        //     cout<<i.first<<':'<<i.second<<' ';
        // }
        // cout<<'\n';
        // for(auto &i: half2){
        //     cout<<i.first<<':'<<i.second<<' ';
        // }
        // cout<<'\n';
        for(auto &i: half1){
            if(half2.count(-i.first))
                ans = max(i.second+half2[-i.first], ans);
        }
        return ans;
    }
};