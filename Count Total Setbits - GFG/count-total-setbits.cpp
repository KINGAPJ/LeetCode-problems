//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
  public:
    ll countBits(long long N) {
        // code here
        ll logg = ceil(log2(N))+1;
        vector<ll> dp(logg, 0);
        vector<ll> pref(logg, 0);
        dp[1] = 1, pref[1] = 1;
        for(int i = 2; i < logg; i++){
            dp[i] = pref[i-1] + (1LL<<(i-1));
            pref[i] = dp[i] + pref[i-1];
        }
        ll ans = 0, cnt = 0;
        for(ll i = logg; i >= 0; i--){
            if(N & (1LL<<i)){
                ans += (pref[i]+1);
                ans += (1LL<<i) * cnt++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends