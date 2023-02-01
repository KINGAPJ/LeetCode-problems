//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

#define ll long long
const ll INF = 1e15 + 1; //max value of ans can be 5*(10^10)
class Solution{   
    vector<vector<ll>> memo;
public:
    ll dp(int i, int col, int r[], int g[], int b[]){
        if(i == 0){
            if(col == 0)
                return memo[i][col] = r[0];
            else if(col == 1)
                return memo[i][col] = g[0];
            else return memo[i][col] = b[0];
        }
        if(memo[i][col] != -1)
            return memo[i][col];
        if(col == 0)
            return memo[i][col] = r[i] + min(dp(i-1, 1, r, g, b), dp(i-1, 2, r, g, b));
        else if(col == 1)
            return memo[i][col] = g[i] + min(dp(i-1, 0, r, g, b), dp(i-1, 2, r, g, b));
        else
            return memo[i][col] = b[i] + min(dp(i-1, 0, r, g, b), dp(i-1, 1, r, g, b));
    }
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        // code here 
        memo = vector<vector<ll>>(n, vector<ll>(3, -1));
        return min({dp(n-1, 0, r, g, b),
                    dp(n-1, 1, r, g, b),
                    dp(n-1, 2, r, g, b)});
        // for(int i = 0; i < 3; i++){
        //     for(int j = 0; j < n; j++){
        //         cout<<memo[j][i]<<' ';
        //     }
        //     cout<<endl;
        // }
        // return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends