//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    vector<string> ans;
public:
    void f(int i, string& formed, string s){
        int n = s.size();
        if(i == n){
            ans.push_back(formed);
            return;
        }
        int j = 0;
        while(j < n){
            while(j+1 < n && s[j] == s[j+1])
                j++;
            if(s[j] != '#'){
                formed.push_back(s[j]);
                char temp = s[j];
                s[j] = '#';
                f(i+1, formed, s);
                s[j] = temp;
                formed.pop_back();
            }
            j++;
        }
    }
	vector<string>find_permutation(string S){
	    sort(S.begin(), S.end());
	    string formed = "";
	    f(0, formed, S);
	    return ans;
	}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends