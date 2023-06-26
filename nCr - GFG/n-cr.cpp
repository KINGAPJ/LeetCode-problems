//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        if(r > n)
            return 0;
        if(n == 1 || r == 0 || r == n)
            return 1;
        r = min(r, n-r);
        vector<vector<int>> curr(2, vector<int> (r+1));
        curr[0][0] = curr[0][1] = 1; //1C0 = 1, 1C1 = 1;
        for(int i = 2; i <= n; i++){
            curr[1][0] = 1;
            for(int j = 1; j <= r; j++)
                curr[1][j] = (curr[0][j-1] + curr[0][j]) % 1000000007;
            curr[0] = curr[1];
        }
        return curr[1][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends