//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        vector<int> indeg(N);
        for(int i = 1; i < p.size(); i++){
            indeg[i]++;
            indeg[p[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < N; i++)
            ans += (indeg[i] > 1);
        return ans < 1 ? 0 : ans-1;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends