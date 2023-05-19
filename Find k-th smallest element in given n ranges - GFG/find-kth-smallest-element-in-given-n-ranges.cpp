//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&ranges, int q, vector<int>queries){
        //Write your code here
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> final;
        final.push_back(ranges.front());
        for(int i = 1; i < ranges.size(); i++){
            if(ranges[i][0] <= final.back()[1]){
                final.back()[1] = max(ranges[i][1], final.back()[1]);
            }else{
                final.push_back(ranges[i]);
            }
        }
        vector<int> ans(q, -1);
        for(int i = 0; i < queries.size(); i++){
            int curr = 0, j = 0;
            for(; j < final.size() && curr + (final[j][1] - final[j][0] + 1) < queries[i]; j++){
                curr += (final[j][1] - final[j][0] + 1);
            }
            if(j < final.size()){
                int which = (queries[i] - curr) - 1;
                ans[i] = final[j][0] + which;
            }
        }
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends