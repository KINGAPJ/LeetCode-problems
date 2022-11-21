//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<vector<int>> ans;
	void rec(int x, int i, vector<int> &nums){
        if(x == 0){
            ans.push_back(nums);
            return;
        }
        if(i == 0)
            return;
        if(i <= x){
            nums.push_back(i);
            rec(x-i, i, nums);
            nums.pop_back();
        }
        rec(x, i-1, nums);
	}
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<int> nums;
        rec(n, n, nums);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends