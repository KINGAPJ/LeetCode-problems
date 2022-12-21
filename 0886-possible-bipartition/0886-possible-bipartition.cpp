class Solution {
    vector<int> twocolor;
    vector<vector<int>> adj;
public:
    bool dfs(int n, int col){
        if(twocolor[n] == -1){
            twocolor[n] = col;
            bool ret = true;
            for(auto &i: adj[n]){
                if(twocolor[i] == col)
                    return false;
                if(twocolor[i] == -1)
                    ret &= dfs(i, 1-col);
            }
            return ret; 
        }else return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        twocolor = vector<int> (n, -1);
        adj = vector<vector<int>>(n);
        for(auto &i: dis){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        bool ret = true;
        for(int i = 0; i < n; i++)
            ret &= dfs(i, 0);
        return ret;
    }
};