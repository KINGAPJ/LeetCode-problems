class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> aux;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < nums[i].size(); j++)
                aux.push_back({i, j, nums[i][j]});
            
        sort(aux.begin(), aux.end(), [&](vector<int> &a, vector<int> &b){
            int as = a[0] + a[1];
            int bs = b[0] + b[1];
            if(as == bs)
                return a[0] > b[0];
            return as < bs;
        });
        
        vector<int> ans;
        for(auto &i: aux){
            ans.push_back(i[2]);
        }
        return ans;
    }
};