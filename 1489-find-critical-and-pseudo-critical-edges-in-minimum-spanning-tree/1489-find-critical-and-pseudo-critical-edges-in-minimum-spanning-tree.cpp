class DSU{
    vector<int> par;
    vector<int> sz;
public:    
    DSU(int n){
        par = sz = vector<int>(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void join(int x, int y){
        x = find(x), y = find(y);
        if(x != y){
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            par[y] = x;
        }
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical, pseudoCritical;
        vector<vector<int>> edgs;
        for(int i = 0; i < edges.size(); i++){
            vector<int> x = {edges[i][2], edges[i][0], edges[i][1], i};
            edgs.push_back(x);
        }
        sort(edgs.begin(), edgs.end());
        set<int> mstedgs;
        int cost = 0, edgsTaken = 0;
        DSU dsu(n);
        for(auto &i: edgs){
            int a = dsu.find(i[1]);
            int b = dsu.find(i[2]);
            if(a != b){
                dsu.join(a, b);
                mstedgs.insert(i[3]);
                cost += i[0];
                edgsTaken++;
            }
            if(edgsTaken == n-1)
                break;
        }
        // for(auto &j: mstedgs){
        for(auto &j: edgs){
            int newCost = 0, newEdgsTaken = 0;
            DSU dsu1(n);
            bool removal = false;
            int remove = -1;
            if(mstedgs.count(j[3])){
                remove = j[3];
                removal = true;
            }else{
                dsu1.join(j[1], j[2]);
                newCost += j[0];
                newEdgsTaken++;
            }
            for(auto &i: edgs){
                if(i[3] == remove)
                    continue;
                int a = dsu1.find(i[1]);
                int b = dsu1.find(i[2]);
                if(a != b){
                    dsu1.join(a, b);
                    newCost += i[0];
                    newEdgsTaken++;
                }
                if(newEdgsTaken == n-1)
                    break;
            }
            if(newCost == cost){
                pseudoCritical.push_back(j[3]);
            }else if(removal){
                critical.push_back(j[3]);
            }
        }
        return {critical, pseudoCritical};
    }
};