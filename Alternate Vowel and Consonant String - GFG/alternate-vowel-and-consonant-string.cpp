//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool isv(char c){return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';}
    string rearrange (string s, int n){
        // your code here
        map<char, int> vows, cons;
        int vs = 0, cs = 0;
        for(auto &i: s)
            if(isv(i))
                vows[i]++, vs++;
            else cons[i]++, cs++;
        if(abs(vs-cs) > 1)
            return "-1";
        s = string(n, '.');
        if(vs > cs || (vs == cs && vows.begin()->first < cons.begin()->first)){
            for(int i = 0; i < n; i += 2){
                char c = vows.begin()->first;
                int f = vows.begin()->second;
                for(int j = 0; j < f; j++){
                    s[i] = c;
                    i += 2;
                }
                vows.erase(c);
                i -= 2;
            }
            for(int i = 1; i < n; i += 2){
                char c = cons.begin()->first;
                int f = cons.begin()->second;
                for(int j = 0; j < f; j++){
                    s[i] = c;
                    i += 2;
                }
                cons.erase(c);
                i -= 2;
            }
        }else if(vs < cs || (vs == cs && vows.begin()->first > cons.begin()->first)){
            for(int i = 0; i < n; i += 2){
                char c = cons.begin()->first;
                int f = cons.begin()->second;
                for(int j = 0; j < f; j++){
                    s[i] = c;
                    i += 2;
                }
                cons.erase(c);
                i -= 2;
            }
            for(int i = 1; i < n; i += 2){
                char c = vows.begin()->first;
                int f = vows.begin()->second;
                for(int j = 0; j < f; j++){
                    s[i] = c;
                    i += 2;
                }
                vows.erase(c);
                i -= 2;
            }
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends