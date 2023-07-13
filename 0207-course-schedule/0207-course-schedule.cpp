class Solution {
public:
    //directed graph cycle detection
    //topological sort or 3 coloring graph method
    vector<vector<int>> adj;
    vector<int> vis;
    
    //3 coloring graph
    bool dfs(int node){
        vis[node] = 1;
        for(auto &x: adj[node]){
            if(vis[x] == 0)
                if(dfs(x))
                    return true;
            if(vis[x] == 1)
                return true;
        }
        vis[node] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prereq) {
        adj.resize(n);
        vis.resize(n, 0);
        for(auto i: prereq)
            adj[i[1]].push_back(i[0]);
        
        // dfs 3 coloring
        // for(int i = 0; i < n; i++)
        //     if(!vis[i] && dfs(i))
        //         return false;
        // return true;
        // ------------
        
        // bfs topological sort
        vector<int> inDeg(n);
        for(int i = 0; i < n; i++){
            for(auto &x: adj[i])
                inDeg[x]++;
        }
        
        queue<int> bfs;
        for(int i = 0; i < n; i++)
            if(inDeg[i] == 0)
                bfs.push(i);
        
        while(!bfs.empty()){
            int u = bfs.front(); bfs.pop();
            n--; //at the end if there is a cycle then all their nodes have non 0 indeg
            for(auto &x: adj[u])
                if(--inDeg[x] == 0)
                    bfs.push(x);
        }
        return n == 0;
    }
};