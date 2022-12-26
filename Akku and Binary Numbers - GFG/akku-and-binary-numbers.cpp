//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution{
public:
    vector<ll> three;
    void precompute(){
        // Code Here
        for(ll i = 0; i < 63; i++){
            ll curr = 0LL | (1LL<<i);
            for(ll j = i+1; j < 63; j++){
                ll curr1 = curr;
                curr1 = curr | (1LL<<j);
                for(ll k = j+1; k < 63; k++){
                    ll curr2 = curr1;
                    curr2 = curr1 | (1LL<<k);
                    three.push_back(curr2);
                }
            }
        }
        sort(three.begin(), three.end());
    }
    
    long long solve(long long l, long long r){
        // Code Here
        ll lo = lower_bound(three.begin(), three.end(), l) - three.begin();
        ll hi = upper_bound(three.begin(), three.end(), r) - three.begin();
        return hi - lo;
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends