//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long> twoOddNum(long long Arr[], long long N)  {
        long long xy = 0, x = 0;
        for(int i = 0; i < N; i++)
            xy ^= Arr[i];
        int setbit = -1;
        for(int i = 0; i < 64; i++){
            if((1LL<<i) & xy){
                setbit = i;
                break;
            }
        }
        for(int i = 0; i < N; i++)
            if((1LL<<setbit) & Arr[i])
                x ^= Arr[i];
        return {max(x^xy, x), min(x^xy, x)};
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