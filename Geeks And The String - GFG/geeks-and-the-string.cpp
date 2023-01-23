//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char> st;
        for(auto &i: s){
            if(st.size() && st.top() == i){
                st.pop();
            }else
                st.push(i);
        }
        string ret = "";
        while(st.size()){
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret == "" ? "-1" : ret;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends