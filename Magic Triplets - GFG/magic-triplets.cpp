//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int ans = 0, n = nums.size();
	    for(int j = 1; j < n-1; j++){
	        int less = 0, more = 0;
	        for(int i = 0; i < j; i++){
	            if(nums[i] < nums[j])
	                less++;
	        }
	        for(int k = j+1; k < n; k++){
	            if(nums[j] < nums[k])
	                more++;
	        }
	        ans += less * more;
	    }
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
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends