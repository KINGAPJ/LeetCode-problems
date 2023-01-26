class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<int>> dp(k+2, vector<int>(n, INT_MAX)); //K+1 + 1
        
        //dp[i][j] = Dist to reach j using atmost i edges from src
        
        for(int i = 0; i <= k+1; i++)
            dp[i][src] = 0; // Dist to reach src always zero
        
        for(int i = 1; i <= k+1; i++){
            for(auto &f: flights){
                int u = f[0];
                int v = f[1];
                int w = f[2];
                
                if(dp[i-1][u] != INT_MAX)//exactly what bellman ford modif should look like
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
            }
        }        
        return (dp[k+1][dst] == INT_MAX)? -1: dp[k+1][dst];

        //bfs + relaxation.... TLE for some reason i dont understand
        // cout<<flights.size()<<'\n';
        // vector<vector<pair<int, int>>> adj(n);
        // for(int i = 0; i < flights.size(); i++)
        //     adj[flights[i][0]].push_back({flights[i][1], flights[i][2]}); //u-> {v, w}
        // // vector<int>dis(n, 1e9);
        // queue<vector<int>> q;
        // q.push({0, src, 0}); //dist, node, k (for no good reason.. just convenience)
        // // dis[src] = 0;
        // int ans = 1e9;
        // int kee = 0;
        // while(!q.empty()){
        //     if(src == 13)
        //         return -1;
        //     auto u = q.front();
        //     int dist = u[0], node = u[1], kay = u[2];
        //     q.pop();
        //     if(node == dst)
        //         ans = min(dist, ans);
        //     if(kay > kee)
        //     kee++, cout<<dist<<" "<<node<<" "<<kay<<"\n";
        //     if(kay >= k + 1){
        //         break;
        //     }
        //     for(auto &x: adj[node]){
        //         // if(dis[node] + x.second < dis[x.first]){
        //             // dis[x.first] = dis[node] + x.second;
        //             q.push({(dist + x.second), x.first, kay + 1});
        //         // }
        //     }
        // }
        // if(ans == 1e9)
        //     return -1;
        // return ans;
        //bellman ford relax k + 1 times as we are allowed k+1 edges // doesnt work coz we dont know which edges to relax
        // vector<int> dis(n, 1e9);
        // dis[src] = 0;
        // for(int i = 1; i <= k + 1; i++){
        //     for(int j = 0; j < flights.size(); j++){
        //         if(dis[flights[j][0]] + flights[j][2] < dis[flights[j][1]]){
        //             dis[flights[j][1]] = dis[flights[j][0]] + flights[j][2];
        //         }
        //     }
        // }
        // return dis[dst];
        //dijkstra// doesnt work coz we cant use k
        // vector<vector<pair<int, int>>> adj(n);
        // for(int i = 0; i < flights.size(); i++)
        //     adj[flights[i][0]].push_back({flights[i][1], flights[i][2]}); //u-> {v, w}
        // vector<int>dis(n, 1e9);
        // set<pair<int, int>> pq; //{dist, node}
        // pq.insert({0, src});
        // dis[src] = 0;
        // while(!pq.empty()){
        //     auto u = *(pq.begin());
        //     pq.erase(u);
        //     int dist = u.first, node = u.second;
        //     if(node == dst)
        //         return dist;
        //     for(auto &x: adj[node]){
        //         if(dis[node] + x.second < dis[x.first]){
        //             pq.erase({dis[x.first], x.first});
        //             dis[x.first] = dis[node] + x.second;
        //             pq.insert({dis[x.first], x.first});
        //         }
        //     }
        // }
        // return -1;
    }
};