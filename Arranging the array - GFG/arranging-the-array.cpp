//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution{
public:
    void merge(int arr[], int l, int m, int r){ //in place merge sort: O(nlogn) instead of O(n^2.logn)
        if(arr[m] < 0)
            return;
        int lefPos = l, rigPos = m+1;
        while(lefPos <= m && arr[lefPos] < 0)
            lefPos++;
        while(rigPos <= r && arr[rigPos] < 0)
            rigPos++;
        reverse(arr+lefPos, arr+m+1); //The swapping part takes O(n^2) in numbers, but here it is only O(n)
        reverse(arr+m+1, arr+rigPos);
        reverse(arr+lefPos, arr+rigPos);
    }
    void mergeSort(int arr[], int l, int r){
        if(l < r){
            int m = l + (r-l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
    void Rearrange(int arr[], int n){
        // Your code goes here
        mergeSort(arr, 0, n-1);
    }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends