//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    long long atMaxk(string &s, int k){
        if(k == 0 || s.size() == 0)
            return 0;
        int frq[26] = {0};
        int i = 0, n = s.size(), uniq = 0;
        long long res = 0;
        for(int j = 0; j < n; j++){
            if(frq[s[j]-'a'] == 0)
                uniq++;
            frq[s[j]-'a']++;
            while(uniq > k){
                frq[s[i]-'a']--;
                if(frq[s[i]-'a'] == 0)
                    uniq--;
                i++;
            }
            res += j-i+1;
        }
        return res;
    }
public:
    long long int substrCount (string s, int k) {
    //code here.
        return atMaxk(s, k) - atMaxk(s, k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends