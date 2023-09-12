//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        if(N == 1)
            return false;
        vector<long long> factors;
        factors.push_back(1);
        for(long long i = 2; i*i <= N; i++)
            if(N%i == 0){
                factors.push_back(i);
                if(i != N/i)
                    factors.push_back(N/i);
            }
        long long sum = accumulate(factors.begin(), factors.end(), 0LL);
        return sum == N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends