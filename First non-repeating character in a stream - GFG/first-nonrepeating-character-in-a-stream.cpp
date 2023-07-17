//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<char> uniqs;
		    string ans = "";
		    vector<bool> vis(26);
		    for(int i = 0; i < A.size(); i++){
		        vector<char>::iterator it;
		        if((it = find(uniqs.begin(), uniqs.end(), A[i])) == uniqs.end() && !vis[A[i]-'a']){
		            uniqs.push_back(A[i]);
		            vis[A[i]-'a'] = true;
		        }else if(it != uniqs.end()){
		            uniqs.erase(it);
		        }
		        if(uniqs.empty())
		            ans.push_back('#');
		        else
		            ans.push_back(uniqs.front());
		    }
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends