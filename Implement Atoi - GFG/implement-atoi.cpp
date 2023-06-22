//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ret = 0;
        if(str[0] == '-'){
            for(int i = 1; i < str.size(); i++){
                if(str[i] >= '0' && str[i] <= '9')
                    ret = ret * 10 + str[i]-'0';
                else
                    return -1;
            }
            return -ret;
        }else{
            for(int i = 0; i < str.size(); i++){
                if(str[i] >= '0' && str[i] <= '9')
                    ret = ret * 10 + str[i]-'0';
                else
                    return -1;
            }
            return ret;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends