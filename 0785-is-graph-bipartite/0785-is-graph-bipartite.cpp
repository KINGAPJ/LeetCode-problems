class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int color = 0;
        int n = graph.size();
        vector<int> colors(n, -1);
        queue<int> bfs;
        for(int j = 0; j < n; j++){
            if(colors[j] == -1){
                bfs.push(j);
                colors[j] = 1;
                while(bfs.size()){
                    auto u = bfs.front();
                    bfs.pop();
                    int currCol = colors[u];
                    for(auto &i: graph[u]){
                        if(colors[i] == -1){
                            colors[i] = !colors[u];
                            bfs.push(i);
                        }else if(colors[i] == colors[u])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};