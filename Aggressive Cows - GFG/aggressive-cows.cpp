//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int lo = 1, hi = 1e9, mid;
        int ans = 1;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            // cout<<"d:"<<mid<<endl;
            int last = 0, cows = 1;
            for(int i = 1; i < n; i++){
                if(stalls[i] - stalls[last] >= mid){
                    last = i;
                    cows++;
                }
            }
            if(cows >= k){
                lo = mid + 1;
                ans = max(ans, mid);
            }else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends