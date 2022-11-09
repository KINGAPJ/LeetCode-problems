//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int ans = INT_MAX;
	    int sum = accumulate(arr, arr+n, 0);
	    int req = sum/2;
	    bool dp[n+1][sum+1];
	    memset(dp, false, sizeof(dp));
	    dp[0][0] = true;
	    for(int i = 1; i <= n; i++){
	        for(int j = 0; j <= sum; j++){
	            if(j >= arr[i-1] && dp[i-1][j-arr[i-1]] || dp[i-1][j]){
	                dp[i][j] = true;
	                if(j == req)
	                    return sum - 2*req;
	                else if(j > req)
	                    ans = min(ans, j);
	            }
	        }
	    }
	   // for(int i = 0; i <= n; i++){
	   //     for(int j = 0; j <= sum; j++){
	   //         cout<<dp[i][j]<<' ';
	   //     }
	   //     cout<<endl;
	   // }
	   // cout<<ans<<"\n";
	    return abs(sum - 2*ans);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends