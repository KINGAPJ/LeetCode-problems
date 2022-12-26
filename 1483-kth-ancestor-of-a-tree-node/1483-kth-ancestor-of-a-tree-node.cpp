class TreeAncestor {//binary lifting
    vector<vector<int>> up;
    // vector<int> depth;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 1+log2(n);
        // LOG = 0;
        // while((1<<LOG) <= n)
        //     LOG++;
        up = vector<vector<int>>(n, vector<int>(LOG));
        // depth = vector<int>(n);
        // parent[0] = 0; //to avoid handling cases of invalid indices where we have to go up finding ancestors
        parent[0] = -1;
        for(int v = 0; v < n; v++)
            up[v][0] = parent[v];
        for(int j = 1; j < LOG; j++)
            for(int v = 0; v < n; v++)
                up[v][j] = up[v][j-1] == -1 ? -1 : up[ up[v][j-1] ][j-1];            
    }
    
    int getKthAncestor(int node, int k) {
        // cout<<depth[node]<<' '<<k<<endl;
        // if(k > depth[node])
        //     return -1;
        for(int j = 0; j < LOG; j++){ //check for all powers of 2
            if(k & (1 << j))  //order doesnt matter: k = 9 = 8+2+1 steps is same as 1+2+8 steps
                node = up[node][j];
            if(node == -1)
                return node;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */