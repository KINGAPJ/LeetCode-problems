//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int r = 0, b = 0, g = 0;
        for(int i = 0; i < n; i++){
            r += a[i] == 'R';
            g += a[i] == 'G';
            b += a[i] == 'B';
        }
        if(r == n || g == n || b == n)
            return n;
        if(((r&1) && (g&1) && (b&1)) || (!(r&1) && !(g&1) && !(b&1)))
            return 2;
        else return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends