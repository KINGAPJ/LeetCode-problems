class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        for(int i = 1; i < (1<<n); i++){
            if(__builtin_popcount(i) == k){
                vector<int> curr;
                for(int j = 0; j < n; j++){
                    if(i & (1<<j))
                        curr.push_back(j+1);
                }
                res.push_back(curr);
            }
        }
        return res;
    }
};