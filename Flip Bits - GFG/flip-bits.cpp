//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n){
        // Your code goes here
        int flips = 0, currones = 0, ones = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == 0){
                currones++;
                flips = max(currones, flips);
            }else{
                currones = max(0, currones-1);
                ones++;
            }
        }
        return flips + ones;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends