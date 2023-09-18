class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < m; i++){
            int x = upper_bound(mat[i].rbegin(), mat[i].rend(), 0) - mat[i].rend();
            int num1 = n-x;
            pq.push({num1, i});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while(pq.size()){
            auto u = pq.top(); pq.pop();
            ans.push_back(u.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};