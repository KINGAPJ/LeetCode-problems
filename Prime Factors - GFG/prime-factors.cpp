//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    int n = N;
	    vector<int> prims;
	    for(int i = 2; i <= N && n > 1; i++){
	        if(n%i == 0){
	            prims.push_back(i);
	            while(n%i == 0){
	                n/=i;
	            }
	        }
	    }
	    return prims;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends