//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        priority_queue<vector<int>> pq;
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        set<pair<int, int>> vis;
        pq.push({A[0]+B[0], 0, 0});
        vector<int> ans;
        vis.insert({0, 0});
        while(ans.size() < K){
            auto u = pq.top(); pq.pop();
            ans.push_back(u[0]);
            int i = u[1], j = u[2];
            if(i+1 < N && !vis.count({i+1, j})){
                vis.insert({i+1, j});
                pq.push({A[i+1]+B[j], i+1, j});
            }
            if(j+1 < N && !vis.count({i, j+1})){
                vis.insert({i, j+1});
                pq.push({A[i]+B[j+1], i, j+1});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends