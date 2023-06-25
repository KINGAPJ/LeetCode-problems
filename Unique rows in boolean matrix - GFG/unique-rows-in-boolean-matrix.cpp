//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col){
        //Your code here
        unordered_set<long long> meow;
        vector<vector<int>> ans;
        for(int i = 0; i < row; i++){
            long long bhow = 0;
            for(int j = 0; j < col; j++){
                bhow |= M[i][j] ? (1LL<<j) : 0;
            }
            meow.insert(bhow);
        }
        for(int i = 0; i < row; i++){
            long long bhow = 0;
            for(int j = 0; j < col; j++){
                bhow |= M[i][j] ? (1LL<<j) : 0;
            }
            if(meow.count(bhow)){
                vector<int> curr;
                for(int j = 0; j < col; j++){
                    curr.push_back(((1LL<<j) & bhow) > 0);
                }
                ans.push_back(curr);
                meow.erase(bhow);
            }
        }
        return ans;
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
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends