//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<int> dp;
  public:
    int f(int price[], int n, int left){
        if(left == 0)
            return 0;
        if(dp[left] != -1)
            return dp[left];
        int ans = 0;
        for(int i = 0; i < left; i++)
            ans = max(ans, f(price, n, left-(i+1)) + price[i]);
        
        return dp[left] = ans;
    }
    int cutRod(int price[], int n) {
        //code here
        dp = vector<int>(n+1, -1);
        return f(price, n, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends