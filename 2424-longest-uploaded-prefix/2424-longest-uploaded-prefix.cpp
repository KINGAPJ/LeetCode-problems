class LUPrefix {
    vector<int> bit;
public:
    LUPrefix(int n) {
        bit = vector<int>(n+2);
    }
    void upload(int video) {
        while(video < bit.size()){
            bit[video] += 1;
            video += video & (-video);
        }
    }
    int query(int v){
        int sum = 0;
        while(v > 0){
            sum += bit[v];
            v -= v & (-v);
        }
        return sum;
    }
    int longest() {
        int lo = 1, hi = bit.size()-1, m, res = 0;
        while(lo <= hi){
            m = lo + (hi - lo)/2;
            if(query(m) == m){
                lo = m + 1;
                res = max(m, res);
            }else
                hi = m - 1;
        }
        return res;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */