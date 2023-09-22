//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<int> find(int arr[], int n , int x ){
        // code here
        int l = lower_bound(arr, arr+n, x) - arr;
        if(l == n)
            return {-1, -1};
        int r = upper_bound(arr, arr+n, x) - arr;
        if(r == 0 || r-1 < l)
            return {-1, -1};
        return {l, r-1};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends