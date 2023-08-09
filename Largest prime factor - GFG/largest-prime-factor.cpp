//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long largestPrimeFactor(int N){
        // code here
        long long ans = 1;
        if(N % 2 == 0){
            ans = max(ans, 2LL);
            while(N % 2 == 0)
                N/=2;
        }
        for(long long i = 3; i*i <= N; i+=2){
            if(N % i == 0){
                ans = max(ans, i);
                while(N % i == 0)
                    N/=i;
            }
        }
        return N == 1 ? ans : N;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends