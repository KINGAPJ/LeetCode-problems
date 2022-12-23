//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    vector<vector<int>> memo;
public:
    int dp(vector<int>& a, int l, int r){
        if(r - l < 2)
            return 0;
        if(memo[l][r] != -1)
            return memo[l][r];
        int maxi = 0;
        for(int i = l+1; i <= r-1; i++)
            maxi = max(maxi, a[l]*a[i]*a[r]+dp(a, l, i)+dp(a, i, r));
        return memo[l][r] = maxi;
    }
    int maxCoins(int n, vector<int> &arr) {
        // code here
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        memo = vector<vector<int>> (n+3, vector<int>(n+3, -1));
        return dp(arr, 0, n+1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends