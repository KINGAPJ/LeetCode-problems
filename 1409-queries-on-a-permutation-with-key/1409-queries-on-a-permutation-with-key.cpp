class BIT{
private:
    vector<int> bit;
public:
    BIT(int size){
        bit = vector<int>(size);
    }
    void update(int i, int val){
        while(i < bit.size()){
            bit[i] += val;
            i += i & (-i);
        }
    }
    int sum(int i){
        int res = 0;
        while(i > 0){
            res += bit[i];
            i -= i & (-i);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        int n = q.size();
        BIT bit(n+m+2);
        unordered_map<int, int> inds;
        for(int i = 1; i <= m; i++){
            bit.update(i+n, 1);
            inds[i] = i+n; //inds[i] = index in the bit
        }
        int currInd = n;
        vector<int> ans;
        for(auto &i: q){
            int currIndBIT = inds[i];
            ans.push_back(bit.sum(currIndBIT-1)); //find the number of people ahead of this
            bit.update(currIndBIT, -1); //remove the guy from his original position
            bit.update(currInd, 1); //push him at ahead of queue
            inds[i] = currInd--; //update this position of BIT in the map
        }
        return ans;
    }
};