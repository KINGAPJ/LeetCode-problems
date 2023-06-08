//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k){
        // code here
        int facs[n+1];
        facs[0] = 1;
        for(int i = 1; i <= n; i++){
            facs[i] = facs[i-1] * i;
        }
        k--;
        string nums = "", ans = "";
        for(int i = 1; i <= n; i++)
            nums.push_back(i+'0');
        int i = n-1;
        while(i){
            int dig = k/facs[i];
            ans.push_back(nums[dig]);
            nums.erase(dig, 1);
            k -= dig*facs[i--];
        }
        ans.push_back(nums[0]);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends