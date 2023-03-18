class DSU{
    vector<int> faction, size;
public:
    DSU(int n){
        faction = vector<int> (n);
        size = vector<int> (n);
        for(int i = 0; i < n; i++)
            faction[i] = i;
    }
    int find_faction(int node){
        if(faction[node] != node)
            return find_faction(faction[node]);
        return faction[node];
    }
    void join_faction(int node, int join){
        int node_faction = find_faction(node); // b
        int faction_to_join = find_faction(join); // a
        if(node_faction != faction_to_join){
            if(size[node_faction] > size[faction_to_join]){
                swap(node_faction, faction_to_join);
            }
            faction[node_faction] = faction_to_join;
            size[faction_to_join] += node_faction;
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> node_vals(n);
        for(int i = 0; i < n; i++)
            node_vals[i] = {vals[i], i};
        sort(node_vals.begin(), node_vals.end());
        vector<vector<vector<int>>> adj(n);
        DSU dsu(n);
        for(auto &i: edges){
            adj[i[0]].push_back({vals[i[1]], i[1]});
            adj[i[1]].push_back({vals[i[0]], i[0]});
        }
        for(int i = 0; i < n; i++)
            sort(adj[i].begin(), adj[i].end());
        int i = 0, ans = n;
        while(i < n){
            int currval = node_vals[i][0], currind = i;
            while(i < n && node_vals[i][0] == currval){
                int val = node_vals[i][0], node = node_vals[i][1];
                for(auto &j: adj[node]){
                    if(j[0] <= val)
                        dsu.join_faction(node, j[1]);
                    else break;
                }
                i++;
            }
            unordered_map<int, int> same_factions;
            for(int k = currind; k < i; k++)
                same_factions[dsu.find_faction(node_vals[k][1])]++;
            // cout<<currval<<':';
            for(auto &j: same_factions){
                ans += (j.second * (j.second - 1) / 2);
                // cout<<j.second<<' ';
            }
            // cout<<'\n';
        }
        return ans;
    }
};