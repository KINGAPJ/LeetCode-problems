class Solution {
public:
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        // constructing adjacency matrix
		vector<vector<pair<int,int>>> graph(n);
        for(auto edge: red_edges)
            graph[edge[0]].emplace_back(edge[1],0); //red edges are denoted by 0 
        for(auto edge: blue_edges)
            graph[edge[0]].emplace_back(edge[1],1); // blue edges are denoted by 1
        vector<int> dist(n,-1); 
        
        queue<vector<int>> q;
        q.emplace(vector<int>{0,0,-1});
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            dist[front[0]] = dist[front[0]] != -1 ? dist[front[0]] : front[1];
            
            for(auto &adj : graph[front[0]]) {
				//Push the node to the queue only if the next edge color is different from the pervious edge color and also if we are visiting the edge
				//for the first time.
                if(front[2] != adj.second && adj.first!= -1) {
                    q.emplace(vector<int>{adj.first, front[1] + 1, adj.second});
					//Update the value in the adjacency matrix to -1 to denote that the node has already been visited.
                    adj.first = -1;
                }
            }
        }
        return dist;
    }
//     vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
//         vector<vector<pair<int, int>>> adj(n);
//         for(int i = 0; i < redEdges.size(); i++){
//             adj[redEdges[i][0]].push_back({redEdges[i][1], 0});
//         }
//         for(int i = 0; i < blueEdges.size(); i++){
//             adj[blueEdges[i][0]].push_back({blueEdges[i][1], 1});
//         }
//         queue<vector<int>> red;
//         queue<vector<int>> blue;
//         // for(auto &x: badj[0])
//         //     blue.push(x);
//         vector<int> ans;
//         ans.push_back(0);
//         for(int i = 1; i < n; i++){
//             for(auto &x: radj[0])
//                 red.push({x,0});
//             int redmin = 1000;
//             while(!red.empty()){
//                 auto x = red.top();
//                 red.pop();
//                 if(x[0] == i){
//                     redmin = x[1];
//                     break;
//                 }
//                 for(auto &it: radj[x[0]]){
                    
//                 }
//             }
//         }
//         return ans;
//     }
};