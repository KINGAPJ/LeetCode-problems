//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long subarrayRanges(int n, vector<int> &arr) {
        // code here
        stack<int> s1, s2;
        vector<int> nsl(n, -1), nsr(n, n);
        vector<int> ngl(n, -1), ngr(n, n);
        for(int i = 0; i < n; i++){
            while(s1.size() && arr[i] <= arr[s1.top()])
                s1.pop();
            while(s2.size() && arr[i] >= arr[s2.top()])
                s2.pop();
            if(s1.size())
                nsl[i] = s1.top();
            if(s2.size())
                ngl[i] = s2.top();
            s1.push(i);
            s2.push(i);
        }
        s1 = s2 = stack<int>();
        for(int i = n-1; i >= 0; i--){
            while(s1.size() && arr[i] < arr[s1.top()])
                s1.pop();
            while(s2.size() && arr[i] > arr[s2.top()])
                s2.pop();
            if(s1.size())
                nsr[i] = s1.top();
            if(s2.size())
                ngr[i] = s2.top();
            s1.push(i);
            s2.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += (1LL*(ngr[i]-i)*(i-ngl[i]) - 1LL*(nsr[i]-i)*(i-nsl[i])) * arr[i];
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
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends