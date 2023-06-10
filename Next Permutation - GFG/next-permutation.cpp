//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        int i = n-1;
        while(i >= 1 && arr[i-1] >= arr[i])
            i--;
        if(i == 0){
            reverse(arr.begin(), arr.end());
            return arr;
        }
        int point = arr[i-1];
        int larger = n-1 - (upper_bound(arr.rbegin(), arr.rbegin()+(n-1-i), point) - arr.rbegin());
        swap(arr[i-1], arr[larger]);
        reverse(arr.begin()+i, arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends