//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> singleNumber(vector<int> nums) {
        // Code here.
        int xorr = 0, n = nums.size(), num1 = 0, num2 = 0;
        for(int i = 0; i < n; i++)
            xorr ^= nums[i];
        int rightmost = -1;
        for(int i = 0; i < 32; i++){
            if(xorr & (1<<i)){
                rightmost = i;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] & (1<<rightmost))
                num1 ^= nums[i];
        }
        num2 = xorr ^ num1;
        return {min(num1, num2), max(num1, num2)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends