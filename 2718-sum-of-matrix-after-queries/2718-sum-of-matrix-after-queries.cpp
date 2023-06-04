#define ll long long
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        unordered_set<int> rs, cs;
        int m = queries.size();
        ll ans = 0;
        for(int i = m-1; i >= 0; i--){
            if(queries[i][0] == 0){
                if(rs.count(queries[i][1]))
                    continue;
                else ans += 1LL * queries[i][2] * (n-cs.size());
                rs.insert(queries[i][1]);
            }else{
                if(cs.count(queries[i][1]))
                    continue;
                else ans += 1LL * queries[i][2] * (n-rs.size());
                cs.insert(queries[i][1]);
            }
        }
        return ans;
    }
};