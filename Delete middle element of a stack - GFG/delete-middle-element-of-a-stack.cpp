//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    bool reached = false;
    public:
    void recur(stack<int> &s, int& sz, int& totSz){
        if(s.empty()){
            reached = true;
            return;
        }
        int top = s.top(); s.pop();
        recur(s, sz, totSz);
        if(!(reached && sz == (totSz-1)/2))
            s.push(top);
        sz++;
    }
    void deleteMid(stack<int>&s, int sizeOfStack){
        // code here.. 
        int currsz = 0;
        recur(s, currsz, sizeOfStack);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends