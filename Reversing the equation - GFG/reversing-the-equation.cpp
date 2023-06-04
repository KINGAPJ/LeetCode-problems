//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s){
        int n = s.size();
        int i = n-1;
        string rev = "";
        while(i >= 0){
            if(s[i] >= '0' && s[i] <= '9'){
                string x = "";
                while(s[i] >= '0' && s[i] <= '9'){
                    x.push_back(s[i]);
                    i--;
                }
                reverse(x.begin(), x.end());
                rev += x;
            }else{
                rev.push_back(s[i]);
                i--;
            }
        }
        return rev;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends