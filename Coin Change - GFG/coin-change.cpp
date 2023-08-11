//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long count(int coins[], int N, int sum) {
        vector<long long> dp(sum+1, 0);
        dp[0] = 1;
        for(long long j = 0; j < N; j++)
            for(long long i = 1; i <= sum; i++){
                dp[i] += (i >= coins[j]) ? dp[i-coins[j]] : 0;
        }
        return dp[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends