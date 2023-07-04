//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        // code here
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
            if(!st.empty())
                ans[i] = arr[st.top()];
            st.push(i);
        }
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
            if(!st.empty())
                ans[i] = arr[st.top()];
            st.push(i);
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
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends