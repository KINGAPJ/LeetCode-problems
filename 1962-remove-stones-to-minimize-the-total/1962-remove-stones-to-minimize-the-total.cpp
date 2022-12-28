class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        multiset<int> hemorrhoids;
        for(auto &i: piles)
            hemorrhoids.insert(i);
        for(int i = 0; i < k; i++){
            int c = *(hemorrhoids.rbegin());
            hemorrhoids.erase(hemorrhoids.find(c));
            hemorrhoids.insert(c-(c>>1));
        }
        int ans = 0;
        for(auto &i: hemorrhoids)
            ans += i;
        return ans;
    }
};