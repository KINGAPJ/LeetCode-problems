class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int ai = 0, bi = 0;
            if(a & (1<<i))
                ai++;
            if(b & (1<<i))
                bi++;
            if(c & (1<<i)){
                ans += (ai+bi) ? 0:1;
            }else
                ans += (ai+bi) ? (ai+bi):0;
        }
        return ans;
    }
};