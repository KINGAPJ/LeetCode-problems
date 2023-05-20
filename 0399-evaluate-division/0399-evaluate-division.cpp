class Solution {
public:
    //union find, dfs
    unordered_map<string, string> dsu;
    
    string union_find(string x){
        if(dsu.find(x) == dsu.end())
            dsu[x] = x;
        if(x != dsu[x])
            dsu[x] = union_find(dsu[x]);
        return dsu[x];
    }
    void union_make(string x, string y){
        x = union_find(x), y = union_find(y);
        if(x != y)
            dsu[y] = x;
    }
    double dfs(string node, map<string, bool> &vis, map<string, vector<pair<string, double>>> &adj, string targ){
        if(node == targ)
            return 1.0;
        vis[node] = true;
        double ans = 0;
        bool yes = false;
        for(auto &x: adj[node]){
            // if(x.first != par)
            if(!vis[x.first])
                ans = max(ans, x.second * dfs(x.first, vis, adj, targ));
            yes = true;
        }
        if(yes)
            return ans;
        else return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& vals, vector<vector<string>>& qs) {
        vector<double> ret;
        map<string, vector<pair<string, double>>> adj;
        map<string, bool> vis;
        for(int i = 0; i < eqs.size(); i++){
            adj[eqs[i][0]].push_back({eqs[i][1], vals[i]});
            adj[eqs[i][1]].push_back({eqs[i][0], 1/vals[i]});
            union_find(eqs[i][0]), union_find(eqs[i][1]);
            union_make(eqs[i][0], eqs[i][1]);
        }
        for(auto &x: adj){
            cout<<"Node: "<<x.first<<"\n";
            for(auto &y: x.second)
                cout<<y.first<<" "<<y.second<<"\n";
            
            cout<<x.first<<"->"<<dsu[x.first]<<"\n";
        }
        for(auto &x: qs){
            if(adj.find(x[0]) != adj.end() && adj.find(x[1]) != adj.end()){
                // if(dsu[x[0]] == dsu[x[1]]){
                if(union_find(x[0]) == union_find(x[1])){
                    ret.push_back(dfs(x[0], vis, adj, x[1]));
                    vis.clear();
                }else ret.push_back(-1.0);
            }else ret.push_back(-1.0);
        }
        return ret;
    }
};