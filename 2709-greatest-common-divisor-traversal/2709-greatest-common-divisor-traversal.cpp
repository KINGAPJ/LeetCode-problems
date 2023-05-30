#define MAXN 100001

int spf[MAXN];
void sieve(){
    spf[1] = 1;
    for(int i = 2; i < MAXN; i++)
        spf[i] = i;
    for(int i = 4; i < MAXN; i += 2)
        spf[i] = 2; 
    for(int i = 3; i*i < MAXN; i++){
        if(spf[i] == i){
            for(int j = i*i; j < MAXN; j += i)
                if(spf[j] == j)
                    spf[j] = i;
        }
    }
}
class DSU{
    vector<int> par, sz;
public:
    DSU(int n){
        par = sz = vector<int>(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    int find(int a){
        if(par[a] == a)
            return a;
        return par[a] = find(par[a]);
    }
    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a != b){
            if(sz[a] < sz[b])
                swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        }
    }
};
class Solution {
public:
    vector<int> getFact(int x){
        vector<int> ret;
        while(x != 1){
            ret.push_back(spf[x]);
            x /= spf[x];
        }
        return ret;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        sieve();
        int n = nums.size();
        DSU dsu(n);
        unordered_map<int, int> pfs;
        sort(nums.begin(), nums.end());
        if(nums.size() == 1)
            return true;
        if(nums.front() == 1)
            return false;
        if(nums.front() == nums.back())
            return true;
        int i = 0;
        while(i < n){
            int m = i;
            while(i < n && nums[m] == nums[i])
                i++;
            auto p_fact = getFact(nums[m]);
            for(auto &p: p_fact){
                if(pfs.count(p)){
                    for(int t = m; t < i; t++){
                        dsu.unite(t, pfs[p]);
                    }
                }else{
                    pfs[p] = m;
                    for(int t = m; t < i; t++){
                        dsu.unite(t, pfs[p]);
                    }
                }
            }
        }
        for(i = 0; i < n; i++){
            if(dsu.find(i) != dsu.find(0))
                return false;
        }
        return true;
    }
};