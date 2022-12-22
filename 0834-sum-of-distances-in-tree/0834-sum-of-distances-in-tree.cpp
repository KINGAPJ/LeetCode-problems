class Solution {
    vector<int> ans, nodes;
    vector<vector<int>> adj;
public:
    void preorder(int x, int par){
        for(auto &i: adj[x]){
            if(i != par){
                preorder(i, x);
                nodes[x] += nodes[i];
                ans[x] += (ans[i] + nodes[i]);
            }
        }
    }
    void postorder(int x, int par){
        int n = adj.size();
        for(auto &i: adj[x]){
            if(i != par){
                ans[i] = ans[x] - nodes[i] + (n - nodes[i]);
                postorder(i, x);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>> (n);
        ans = vector<int>(n);
        nodes = vector<int>(n, 1);
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        preorder(0, -1);
        postorder(0, -1);
        return ans;
    }
};