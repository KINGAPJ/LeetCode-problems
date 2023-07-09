//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    int missingNumber(int arr[], int n) { 
        int ans = 0;
        for(int i = 0; i < n; i++){
            int curr = arr[i];
            while(curr <= n && curr >= 1 && arr[curr-1] != curr){
                swap(arr[i], arr[curr-1]);
                curr = arr[i];
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] != i+1)
                return i+1;
        }
        return n+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends