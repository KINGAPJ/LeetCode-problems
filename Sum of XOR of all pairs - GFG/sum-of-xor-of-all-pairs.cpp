//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n){
    //Complete the function
        long long ans = 0;
        for(int bit = 0; bit < 32; bit++){
            int zeros = 0, ones = 0;
            for(int i = 0; i < n; i++){
                if(1 & (arr[i] >> bit))
                    ones++;
                else
                    zeros++;
            }
            ans += (1LL << bit) * (1LL * zeros * ones);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends