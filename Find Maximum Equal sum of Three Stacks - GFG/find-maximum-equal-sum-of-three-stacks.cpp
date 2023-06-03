//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        unordered_map<int, int> mp;
        int curr = 0, ans = 0;
        for(int i = N1-1; i >= 0; i--){
            curr += S1[i];
            mp[curr]++;
        }
        curr = 0;
        for(int i = N2-1; i >= 0; i--){
            curr += S2[i];
            if(mp.count(curr))
                mp[curr]++;
        }
        curr = 0;
        for(int i = N3-1; i >= 0; i--){
            curr += S3[i];
            if(mp.count(curr) && mp[curr] == 2)
                mp[curr]++;
        }
        for(auto &i: mp){
            if(i.second == 3)
                ans = max(ans, i.first);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends