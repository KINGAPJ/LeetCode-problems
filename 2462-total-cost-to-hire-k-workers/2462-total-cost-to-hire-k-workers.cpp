class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = costs.size();
        // cout<<n<<'\n';
        long long ans = 0;
        candidates *= 2;
        int i = 0, j = n-1;
        while(i < n && j >= 0 && i <= j && candidates){
            candidates--;
            pq.push({costs[i], i});
            i++;
            if(i <= j){
                candidates--;
                pq.push({costs[j], j});
                j--;
            }
        }
        while(k){
            auto [cost, index] = pq.top();
            pq.pop();
            // cout<<costs[i]<<' '<<costs[j]<<'\n';
            if(i <= j){
                if(index < i){
                    pq.push({costs[i], i});
                    i++;
                }else{
                    pq.push({costs[j], j});
                    j--;
                }
            }
            ans += cost;
            k--;
        }
        return ans;
    }
};