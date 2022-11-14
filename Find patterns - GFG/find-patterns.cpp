//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here
        int n = s.size(), m = w.size();
        vector<int> frq(m);
        vector<vector<int>> mp(26);
        for(int i = 0; i < m; i++)
            mp[w[i]-'a'].push_back(i);
        for(auto &i: s){
            int t = 0;
            if(t = mp[i-'a'].size()){
                for(int j = t-1; j >= 0; j--){
                    auto x = mp[i-'a'][j];
                    if(x > 0){
                        if(frq[x-1] > 0){
                            frq[x-1]--;
                            frq[x]++;
                            break;
                        }
                    }else{
                        frq[x]++;
                        break;
                    }
                }
            }
        }
        return frq.back();
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends