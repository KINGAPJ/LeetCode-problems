class DSU{
    vector<int> nodes, sz;
public:
    DSU(int n){
        sz = vector<int>(n, 1);
        nodes = vector<int>(n);
        iota(nodes.begin(), nodes.end(), 0);
    }
    int find(int v){
        if(v == nodes[v])
            return v;
        return nodes[v] = find(nodes[v]); //assigning is an optimization
    }
    void unify(int a, int b){
        a = find(a), b = find(b);
        if(a != b){
            if(sz[a] < sz[b])
                swap(a, b);
            nodes[b] = a;
            sz[a] += sz[b];
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> alice, bob, both;
        for(auto &i: edges){
            if(i[0] == 1)
                alice.push_back(i);
            else if(i[0] == 2)
                bob.push_back(i);
            else
                both.push_back(i);
        }
        DSU Alice(n), Bob(n);
        int al_cnt = 0, bo_cnt = 0, commoncnt = 0;
        for(auto &i: both){
            if(Alice.find(i[1]-1) != Alice.find(i[2]-1)){ //since common are first.. not alice also means not bob
                commoncnt++;
                Alice.unify(i[1]-1, i[2]-1);
                Bob.unify(i[1]-1, i[2]-1);
            }
        }
        if(commoncnt == n-1)
            return edges.size() - commoncnt;
        for(auto &i: alice){
            if(Alice.find(i[1]-1) != Alice.find(i[2]-1)){
                al_cnt++;
                Alice.unify(i[1]-1, i[2]-1);
            }
        }
        for(auto &i: bob){
            if(Bob.find(i[1]-1) != Bob.find(i[2]-1)){
                bo_cnt++;
                Bob.unify(i[1]-1, i[2]-1);
            }
        }
        if(commoncnt + al_cnt == n-1 && commoncnt + bo_cnt == n-1)
            return edges.size() - (commoncnt + al_cnt + bo_cnt);
        return -1;
    }
};