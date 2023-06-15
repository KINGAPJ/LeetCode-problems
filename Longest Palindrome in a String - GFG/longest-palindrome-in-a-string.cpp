//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        string s = "$" + S + "#";
        int n = s.size(), maxi = 0, st = 0;
        for(int i = 1; i < n-1; i++){
            int j = i;
            while(j < n && s[i] == s[j])
                j++;
            int k = i-1;
            while(k >= 0 && j < n && s[j] == s[k]){
                j++, k--;
            }
            if(j-k-1 > maxi){
                maxi = j-k-1;
                st = k+1;
            }
        }
        return s.substr(st, maxi);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends