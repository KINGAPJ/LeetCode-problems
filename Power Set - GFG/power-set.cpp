//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int mosk = s.size();
		    vector<string> ans;
		    for(int i = 1; i < (1<<mosk); i++){
		        string curr = "";
		        for(int j = 0; j < mosk; j++){
		            if(i & (1<<j)){
		                curr.push_back(s[j]);
		            }
		        }
		        ans.push_back(curr);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends