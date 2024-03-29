//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]){
        // your code here
        vector<int> dp(n, INT_MAX);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int x = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[x] = a[i];
            ans = max(ans, 1 + x);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends