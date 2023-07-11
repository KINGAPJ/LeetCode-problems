//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k){
        // Your code goes here.
        int count=0;
        unordered_set<int> s;
        int i = 0, j = 0;
        bool rev=true;
        while(count <= n*m){
            if(rev){
                while(j < m && s.find(i*m + j)==s.end()){
                    count++;
                    s.insert(i*m + j);
                    if(count == k)
                    return a[i][j];
                    j++;
                }
                j--; i++;
                while(i < n && s.find(i*m + j)==s.end()){
                    count++;
                    s.insert(i*m + j);
                    if(count == k)
                    return a[i][j];
                    i++;
                }
                i--; j--;
            }else{
                while(j>=0 &&  s.find(i*m+j)==s.end()){
                    count++;
                    s.insert(i*m + j);
                    if(count == k)
                    return a[i][j];
                    j--;
                }
                j++; i--;
                while(i >= 0 && s.find(i*m + j)==s.end()){
                    count++;
                    s.insert(i*m + j);
                    if(count == k)
                    return a[i][j];
                    i--;
                }
                i++; j++;
            }
            rev = !rev;
        }
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends