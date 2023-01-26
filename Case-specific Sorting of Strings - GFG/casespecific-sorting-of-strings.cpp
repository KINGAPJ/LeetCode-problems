//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    string caseSort(string str, int n){
        vector<int> lowercase(26), uppercase(26);
        for(int i = 0; i < n; i++){
            if(str[i] >= 97 && str[i] <= 122)
                lowercase[str[i]-'a']++;
            else
                uppercase[str[i]-'A']++;
        }
        int currL = 0, currU = 0;
        for(int i = 0; i < n; i++){
            if(str[i] >= 97 && str[i] <= 122){
                while(lowercase[currL] == 0)
                    currL++;
                lowercase[currL]--;
                str[i] = 'a' + currL;
            }else{
                while(uppercase[currU] == 0)
                    currU++;
                uppercase[currU]--;
                str[i] = 'A' + currU;
            }
        }
        return str;
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends