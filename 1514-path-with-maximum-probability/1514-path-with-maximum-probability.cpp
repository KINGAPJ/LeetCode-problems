class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        set<pair<double, int>> pq;
        vector<double> dis(n, 0);
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        dis[start] = 1;
        pq.insert({-1, start});
        while(!pq.empty()){
            auto u = *(pq.begin());
            double prob = -u.first;
            int node = u.second;
            pq.erase(u);
            for(auto &i: adj[node]){
                if(prob * i.second > dis[i.first]){
                    pq.erase({-dis[i.first], i.first});
                    dis[i.first] = prob * i.second;
                    pq.insert({-dis[i.first], i.first});
                }
            }
        }
        return dis[end];
    }
};