class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust){
        vector<int> id(n+1, 0), od(n+1, 0);
        int ans = -1;
        for(int i = 0; i < trust.size(); i++){
            id[trust[i][1]]++;
            od[trust[i][0]]++;
        }
        for(int i = 1; i <= n; i++){
            if(id[i] == n - 1 && od[i] == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
    // int indeg(vector<vector<int>> &adj){
    //     int n = adj.size();
    //     vector<int> in(n,0);
    //     int  outd = 0;
    //     for(int i = 0; i < n; i++){
    //         outd = adj[i].size();
    //         for(int j = 0; j < adj[i].size(); j++){
    //             in[i]++;
    //         }
    //         if(in[i] == n-1 && outd == 0){
    //             return i + 1;
    //         }
    //          outd = 0;
    //     }
    //     return -1;
    // }
    // int findJudge(int n, vector<vector<int>>& trust) {
    //     vector<vector<int>> adj(n+1);
    //     for(int i = 0; i < trust.size(); i++){
    //         adj[trust[i][0]].push_back(trust[i][1]);
    //     }
    //     return indeg(adj);
    // }
};