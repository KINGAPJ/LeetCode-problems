//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int Count(int L, int R){
		    // Code here
		    vector<bool> sieve(R+1);
		    if(L == 1)
		        L = 2;
		    sieve[0] = 1;
		    sieve[1] = 1;
		    for(int i = 2; i*i <= R; i++){
		        
		        if(sieve[i] == 0){
		            for(int j = 2*i; j <= R; j += i)
		                sieve[j] = 1;
		        }
		    }
		    int ans = 0;
		    for(int i = L; i <= R; i++){
		        ans += sieve[i];
		    }
		    return ans - (R - L + 1 - ans);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int L, R;
		cin >> L >> R;
		Solution obj;
		int ans = obj.Count(L, R);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends