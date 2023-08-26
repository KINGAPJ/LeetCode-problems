class Solution {
    vector<int> one;
    vector<int> nums;
    int ans = INT_MAX;
    void generate(int i, int sum){
        int n = nums.size();
        if(i == n/2){
            one.push_back(sum);
            return;
        }
        generate(i+1, sum+nums[i]);
        generate(i+1, sum);
    }
    void check(int i, int sum, int& goal){
        int n = nums.size();
        if(i == n){
            int tar = goal - sum;
            int moreind = lower_bound(one.begin(), one.end(), tar) - one.begin();
            int lessind = moreind-1;
            if(moreind < one.size())
                ans = min(ans, abs(goal-(sum+one[moreind])));
            if(lessind >= 0)
                ans = min(ans, abs(goal-(sum+one[lessind])));
            return;
        }
        check(i+1, sum+nums[i], goal);
        check(i+1, sum, goal);
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        this->nums = nums;
        generate(0, 0);
        int n = nums.size();
        sort(one.begin(), one.end());
        check(n/2, 0, goal);
        return ans;
    }
};