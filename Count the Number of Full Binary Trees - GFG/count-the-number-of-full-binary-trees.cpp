//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    #define ll long long
    const ll mod = 1e9 + 7;
    long long int numoffbt(long long int arr[], int n){
        // Your code goes here
        ll maxx = *max_element(arr, arr+n);
        ll minn = *min_element(arr, arr+n);
        ll stor[maxx+2] = {0}, val[maxx+2] = {0};
        for(int i = 0; i < n; i++)
            stor[arr[i]] = val[arr[i]] = 1;
        ll ans= 0;
        for(ll i = minn; i <= maxx; i++){
            if(stor[i]){
                for(int j = i+i; j <= maxx && j/i <= i; j += i){
                    if(!stor[j])
                        continue;
                    val[j] = (val[j] + val[i] * val[j/i]) % mod;
                    if(i != j/i)
                        val[j] = (val[j] + val[i] * val[j/i]) % mod;
                }
            }
            ans = (ans + val[i]) % mod;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends