class Solution {
    vector<int> par;
    vector<vector<int>> adj;
    set<vector<int>> guess;
    vector<bool> vis;
    int k;
public:
    int dfs(int node){
        vis[node] = true;
        int ret = 0;
        for(auto &i: adj[node]){
            if(!vis[i]){
                if(guess.count({node, i}))
                    ret++;
                par[i] = node;
                ret += dfs(i);
            }
        }
        return ret;
    }
    void dfs1(int node, int& pos, int& ans){
        vis[node] = true;
        for(auto &i: adj[node]){
            if(!vis[i]){
                if(guess.count({node, i}))
                    pos--;
                if(guess.count({i, node}))
                    pos++;
                if(pos >= k)
                    ans++;
                dfs1(i, pos, ans);
                if(guess.count({node, i}))
                    pos++;
                if(guess.count({i, node}))
                    pos--;
            }
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        this->k = k;
        par = vector<int> (n, -1);
        adj = vector<vector<int>> (n);
        vector<int> indeg(n);
        vis = vector<bool> (n);
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++, indeg[i[1]]++;
        }
        guess = set<vector<int>> (guesses.begin(), guesses.end());
        int st = -1, ans = 0, currdfs = 0;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 1){
                par[i] = i;
                currdfs = dfs(i);
                ans = (currdfs >= k) ? 1 : 0;
                st = i;
                break;
            }
        }
        // cout<<st<<'\n';
        vis = vector<bool> (n);
        dfs1(st, currdfs, ans);
        return ans;
    }
};