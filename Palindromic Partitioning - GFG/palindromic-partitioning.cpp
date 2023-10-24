//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string s){
        // code here
        int n = s.size();
        vector<int> cuts(n+1);
        iota(cuts.begin(), cuts.end(), 0);
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for(int r = 1; r < n; r++){
            for(int l = r; l >= 0; l--){
                if(l == r || (s[l] == s[r] && (l+1 == r || dp[l+1][r-1]))){
                    dp[l][r] = true;
                    cuts[r+1] = min(cuts[r+1], 1+cuts[l]);
                }
            }
        }
        return cuts[n]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends