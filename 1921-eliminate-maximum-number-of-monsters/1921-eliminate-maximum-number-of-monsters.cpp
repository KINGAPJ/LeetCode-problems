class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size(), ans = 0;
        for(int i = 0; i < n; i++)
            dist[i] = (dist[i]+speed[i]-1)/speed[i];
        sort(dist.begin(), dist.end());
        for(int i = 0; i < n; i++){
            if(dist[i] < i+1)
                break;
            ans++;
        }
        return ans;
    }
};