//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long prod = 1;
        long long ans = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            prod *= a[r];
            while(l < r && prod >= k){
                prod /= a[l];
                l++;
            }
            if(prod < k)
                ans += (r-l+1);
        }
        // cout<<l<<' '<<n<<' '<<ans<<'\n';
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends