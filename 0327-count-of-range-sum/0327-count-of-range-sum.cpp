class BIT{
    vector<int> bit;
public:
    BIT(int size){
        bit = vector<int>(size+1);
        for(int i = 0; i < size; i++)
            update(i+1, 1);
    }
    void update(int i, int val){
        while(i < bit.size()){
            bit[i] += val;
            i += i & (-i);
        }
    }
    int query(int i){
        int res = 0;
        while(i > 0){
            res += bit[i];
            i -= i & (-i);
        }
        return res;
    }
};
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> pref(n+1);
        for(int i = 0; i < n; i++)
            pref[i+1] = pref[i] + nums[i];
        vector<long long> sortedPref = pref;
        sort(sortedPref.begin(), sortedPref.end());
        BIT bit(n+1);
        int ans = 0;
        for(auto &i: pref){
            int ind = lower_bound(sortedPref.begin(), sortedPref.end(), i) - sortedPref.begin();
            int l = (lower_bound(sortedPref.begin(), sortedPref.end(), i+lower) - sortedPref.begin()) - 1;
            int u = (upper_bound(sortedPref.begin(), sortedPref.end(), i+upper) - sortedPref.begin()) - 1;
            bit.update(ind+1, -1);
            ans += bit.query(u+1) - bit.query(l+1);
        }
        return ans;
    }
};