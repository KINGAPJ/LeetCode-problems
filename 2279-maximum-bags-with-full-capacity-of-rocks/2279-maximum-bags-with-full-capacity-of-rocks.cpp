class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        for(int i = 0; i < n; i++)
            rocks[i] = capacity[i] - rocks[i];
        sort(rocks.begin(), rocks.end());
        int ans = 0;
        for(auto &i: rocks){
            int add = min(additionalRocks, i);
            additionalRocks -= add;
            i -= add;
            if(i == 0)
                ans++;
            if(additionalRocks == 0)
                break;
        }
        return ans;
    }
};