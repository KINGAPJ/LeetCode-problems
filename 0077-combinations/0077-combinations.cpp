class Solution {
    vector<vector<int>> res;
    void recur(int n, int k, vector<int>& curr){
        if(k == 0){
            res.push_back(curr);
            return;
        }
        if(n == 0)
            return;
        curr.push_back(n);
        recur(n-1, k-1, curr);
        curr.pop_back();
        recur(n-1, k, curr);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        recur(n, k, curr);
        return res;
    }
};