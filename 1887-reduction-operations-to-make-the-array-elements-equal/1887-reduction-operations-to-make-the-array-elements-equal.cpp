class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> frq;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            frq[nums[i]]++;
        frq.erase(frq.begin());
        int pref = 0, ans = 0;
        for(map<int, int>::reverse_iterator i = frq.rbegin(); i != frq.rend(); i++){
            pref += i->second;
            ans += pref;
        }
        return ans;
    }
};