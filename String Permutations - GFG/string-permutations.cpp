//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    vector<string> ans;
    void f(string &s, string curr){
        int n = s.size();
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        for(int j = 0; j < n; j++){
            if(s[j] != '#'){
                char temp = s[j];
                s[j] = '#';
                curr.push_back(temp);
                f(s, curr);
                curr.pop_back();
                s[j] = temp;
            }
        }
    }
    public:
    //Complete this function
    vector<string> permutation(string S){
        //Your code here
        f(S, "");
        sort(ans.begin(), ans.end());
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
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends