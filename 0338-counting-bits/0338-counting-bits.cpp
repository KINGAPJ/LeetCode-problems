class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1);
        for(int i = 1; i <= n; i++)
            if(i&1)
                ret[i] = 1 + ret[i>>1];
            else ret[i] = ret[i>>1];
        return ret;
    }
};