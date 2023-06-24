//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Node{
    Node* next[26];
    int count;
public:
    void set(char c){next[c-'a'] = new Node();}
    Node* get(char c){return next[c-'a'];}
    int getc(){return count;}
    void inc(){count++;}
};
class Trie{
    Node* root;
public:
    Trie(){root = new Node();}
    void insert(string& str, int k){
        Node* node = root;
        for(int i = 0; i < min((int)str.size(), k); i++){
            if(!node->get(str[i])){
                node->set(str[i]);
            }
            node = node->get(str[i]);
        }
        node->inc();
    }
    int samePrefixes(string &str, int k){
        Node* node = root;
        for(int i = 0; i < min((int)str.size(), k); i++){
            if(!node->get(str[i])){
                return 0;
            }
            node = node->get(str[i]);
        }
        return node->getc();
    }
};
class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        if(k > str.size())
            return 0;
        Trie trie;
        for(int i = 0; i < n; i++){
            trie.insert(arr[i], k);
        }
        return trie.samePrefixes(str, k);
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
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends