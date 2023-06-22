//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) { 
        reverse(S.begin(), S.end());
        int st = 0, en = 0;
        for(int i = 0; i <= S.size(); i++){
            if(i == S.size() || S[i] == '.'){
                en = i;
                reverse(S.begin()+st, S.begin()+en);
                st = i+1;
            }
        }
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends