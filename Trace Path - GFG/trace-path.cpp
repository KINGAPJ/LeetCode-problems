//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int minm = 0, maxm = 0, minn = 0, maxn = 0;
        int currx = 0, curry = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                curry -= 1;
                minm = min(curry, minm);
                maxm = max(curry, maxm);
            }else if(s[i] == 'R'){
                curry += 1;
                minm = min(curry, minm);
                maxm = max(curry, maxm);
            }else if(s[i] == 'D'){
                currx -= 1;
                minn = min(currx, minn);
                maxn = max(currx, maxn);
            }else{
                currx += 1;
                minn = min(currx, minn);
                maxn = max(currx, maxn);
            }
        }
        return maxm - minm + 1 <= m && maxn - minn + 1 <= n;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends