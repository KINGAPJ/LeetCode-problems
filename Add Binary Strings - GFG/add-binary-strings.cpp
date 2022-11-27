//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b){
	    // your code here
	    reverse(a.begin(), a.end());
	    reverse(b.begin(), b.end());
	    while(a.size() && a.back() == '0')
	        a.pop_back();
	    while(b.size() && b.back() == '0')
	        b.pop_back();
	    if(a.size() < b.size())
	        swap(a, b);
	    int c = 0, s = 0, i = 0;
	    // cout<<a<<" "<<b<<endl;
	    for(i = 0; i < b.size(); i++){
	        s = (a[i]-'0' + b[i]-'0' + c);
	        // cout<<"s: "<<s;
	        a[i] = (s&1) +'0';
	        c = s>>1;
	        // cout<<"c: "<<c<<endl;
	    }
	    for(; i < a.size(); i++){
	        s = (a[i]-'0'+c);
	        // cout<<"s: "<<s;
	        a[i] = (s&1) + '0';
	        c = s>>1;
	        // cout<<"c: "<<c<<endl;
	    }
	    if(c == 1)
	        a.push_back('1');
	   reverse(a.begin(), a.end());
	   return a;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends