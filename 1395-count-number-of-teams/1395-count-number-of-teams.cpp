/*
Iterate over every elmeent as the middle soldier. 
We just need to find the 
(number of soldiers less in rating than him) * (number of soldiers more in rating than him)

To do this we do range updates and range queries using BIT to keep prefix and suffix arrays
*/
class BIT{
private:
    vector<int> bit;
public:
    BIT(int size){ bit = vector<int>(size); }
    void rangeupdate(int ind, int del){
        while(ind < bit.size()){
            bit[ind] += del;
            ind += ind & (-ind);
        }
    }
    int prefixSum(int ind){
        int res = 0;
        while(ind > 0){
            res += bit[ind];
            ind -= ind & (-ind);
        }
        return res;
    }
    int suffixSum(int ind){
        return prefixSum(bit.size()-1) - prefixSum(ind-1);
    }
};
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int hi = *max_element(rating.begin(), rating.end());
        BIT left(hi+1), right(hi+1);
        for(auto &i: rating)
            right.rangeupdate(i, 1);
        int ans = 0;
        for(auto &i: rating){
            right.rangeupdate(i, -1);
            ans += left.prefixSum(i-1) * right.suffixSum(i+1);
            ans += right.prefixSum(i-1) * left.suffixSum(i+1);
            left.rangeupdate(i, 1);
        }
        return ans;
    }
};