class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1 || n == k)
            return 0;
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int> pq2;
        long long ans = 0;
        for(int i = 1; i < n; i++){
            pq1.push(weights[i]+weights[i-1]);
            pq2.push(weights[i]+weights[i-1]);
            if(pq1.size() > k-1){
                pq1.pop();
            }
            if(pq2.size() > k-1){
                pq2.pop();
            }
        }
        while(!pq1.empty()){
            ans += pq1.top();
            pq1.pop();
        }
        while(!pq2.empty()){
            ans -= pq2.top();
            pq2.pop();
        }
        return ans;
    }
};