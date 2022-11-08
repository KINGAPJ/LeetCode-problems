//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long x = 0;
        for(int i = 0; i < N; i++)
            x ^= Arr[i];
        int diff = -1;
        for(int i = 0; i < 64; i++)
            if((1<<i) & x){
                diff = i;
                break;
            }
        long long first = 0, second = 0;
        for(int i = 0; i < N; i++){
            if(Arr[i] & (1<<diff))
                first ^= Arr[i];
            else second ^= Arr[i];
        }
        return {max(first, second), min(first, second)};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends