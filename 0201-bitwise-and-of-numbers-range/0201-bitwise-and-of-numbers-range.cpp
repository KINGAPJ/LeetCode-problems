class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        vector<int> bits(32);
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int l = (left & (1<<i)), r = (right & (1<<i));
            if(l && r){
                ans += 1<<i;
            }else if(l ^ r)
                ans = 0;
        }
        return ans;
    }
};