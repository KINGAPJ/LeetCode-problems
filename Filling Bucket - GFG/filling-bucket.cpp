//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod = 1e8;
    int fillingBucket(int N) {
        // code here
        if(N <= 2)
            return N;
        int a = 1, b = 2;
        int ans = 1;
        for(int i = N-2; i > 0; i--){
            ans = (a % mod + b % mod) % mod;
            a = b % mod;
            b = ans % mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends