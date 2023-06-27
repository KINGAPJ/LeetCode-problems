class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long n1 = nums1.size(), n2 = nums2.size();
        k = min(n1*n2, 0LL+k);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        set<vector<int>> pq;
        pq.insert({nums1[0]+nums2[0], 0, 0});
        vector<vector<int>> ans;
        while(k--){
            auto u = *pq.begin();
            pq.erase(u);
            // cout<<u[0]<<' '<<u[1]<<' '<<u[2]<<'\n';
            ans.push_back({nums1[u[1]], nums2[u[2]]});
            if(u[2]+1 < n2)
                pq.insert({nums1[u[1]]+nums2[u[2]+1], u[1], u[2]+1});
            if(u[1]+1 < n1)
                pq.insert({nums1[u[1]+1]+nums2[u[2]], u[1]+1, u[2]});
        }
        return ans;
    }
};