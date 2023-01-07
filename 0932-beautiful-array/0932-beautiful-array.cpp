class Solution {
    unordered_map<int, vector<int>> memo;
public:
    vector<int> rec(int n){ //solution recursively built.. so every big array has same property
        if(memo.count(n))
            return memo[n];
        vector<int> res;
        if(n == 1)
            res.push_back(1);
        else{
            for(auto &x: rec((n+1)/2))
                res.push_back(2*x - 1); //push the odd guys 
            for(auto &x: rec(n/2))
                res.push_back(2*x);
        }
        return memo[n] = res;
    }
    vector<int> beautifulArray(int n) {
        return rec(n);
    }
};