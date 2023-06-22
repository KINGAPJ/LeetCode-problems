//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXORn(int n){
        switch(n%4){
            case 0: return n;
            case 1: return 1;
            case 2: return n+1;
            case 3: return 0;
        }
    }
    int findXOR(int l, int r) {
        return findXORn(r) ^ findXORn(l-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends