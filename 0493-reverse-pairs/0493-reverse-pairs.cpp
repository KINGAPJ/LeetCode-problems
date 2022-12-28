class BIT{
    vector<int> bit;
public:
    BIT(int size){
        bit = vector<int>(size + 1);
    }
    int query(int i){//opposite direction
        int sum = 0;
        while(i < bit.size()){
            sum += bit[i];
            i += i & -i;
        }
        return sum;
    }
    void update(int i){//opposite direction
        while(i > 0){
            bit[i]++;
            i -= i & -i;
        }
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        BIT bit(nums.size());
        for(auto &i: nums){
            int X2 = lower_bound(sortedNums.begin(), sortedNums.end(), 2LL*i+1) - sortedNums.begin();
            int X = lower_bound(sortedNums.begin(), sortedNums.end(), i) - sortedNums.begin();
            ans += bit.query(X2+1);
            bit.update(X+1);
        }
        return ans;
    }
};