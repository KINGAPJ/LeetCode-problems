class Solution {
public:
    map<pair<int, int>, int> memo;
    bool dp(vector<int> &stones, int i, int k){
        int n = stones.size();
        if(i == n-1){
            return true;
        }
        if(memo.count({i, k}))
            return memo[{i, k}] == 1;
        int k_minus_1 = -1;
        if(k > 1){
            k_minus_1 = lower_bound(stones.begin()+i+1, stones.end(), stones[i] + k-1) - stones.begin();
            if(k_minus_1 >= n or stones[k_minus_1] != stones[i]+k-1)
                k_minus_1 = -1;
        }
        int k_ = -1;
        k_ = lower_bound(stones.begin()+i+1, stones.end(), stones[i] + k) - stones.begin();
        if(k_ >= n or stones[k_] != stones[i]+k)
            k_ = -1;
        int k_plus_1 = -1;
        k_plus_1 = lower_bound(stones.begin()+i+1, stones.end(), stones[i] + k+1) - stones.begin();
        if(k_plus_1 >= n or stones[k_plus_1] != stones[i]+k+1)
            k_plus_1 = -1;
        bool yes = false;
        if(k_minus_1 != -1){
            yes |= dp(stones, k_minus_1, k-1);
            if(yes)
                return memo[{i, k}] = yes;
        }
        if(k_ != -1){
            yes |= dp(stones, k_, k);
            if(yes)
                return memo[{i, k}] = yes;
        }
        if(k_plus_1 != -1){
            yes |= dp(stones, k_plus_1, k+1);
            if(yes)
                return memo[{i, k}] = yes;
        }
        return memo[{i, k}] = yes;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)
            return false;
        return dp(stones, 1, 1);
    }
};
// cout<<"{"<<i<<","<<k<<"}: "<<k_minus_1<<' '<<k_<<' '<<k_plus_1<<' '<<endl;
// bool yes = dp(stones, 1, 1);
//         for(auto &i: memo){
//             cout<<"{"<<i.first.first<<","<<i.first.second<<"}: "<<i.second<<endl;
//         }
//         return yes;