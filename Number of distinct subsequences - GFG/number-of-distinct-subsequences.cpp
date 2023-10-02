//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s){
	    // Your code goes here
        int n = s.size(), mod = 1e9 + 7;
        int dp[n+1] = {0}, last[26];
        dp[0] = 1;
        memset(last, -1, sizeof(last));
        for(int i = 0; i < n; i++){
            if(last[s[i]-'a'] == -1){
                dp[i+1] = (2*dp[i]) % mod;
            }else{
                dp[i+1] = ((2*dp[i]) % mod - dp[last[s[i]-'a']] + mod) % mod ;
            }
            last[s[i]-'a'] = i;
        }
        return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends