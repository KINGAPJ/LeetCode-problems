//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    vector<Node*> nx = vector<Node*>(26);
    vector<int> inds;
  public:
    Node* next(char c){return nx[c-'A'];}
    void set(char c){nx[c-'A'] = new Node();}
    void insert(int idx){inds.push_back(idx);}
    vector<int> ind(){return inds;}
};
class Trie{
    Node* root;
  public:
    Trie(){root = new Node();}
    void push(string word, int idx){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                if(!node->next(word[i]))
                    node->set(word[i]);
                node = node->next(word[i]);
            }
        }
        node->insert(idx);
    }
    vector<int> search(string pat){
        Node* node = root;
        for(int i = 0; i < pat.size(); i++){
            if(pat[i] >= 'A' && pat[i] <= 'Z'){
                if(!node->next(pat[i]))
                    return {};
                node = node->next(pat[i]);
            }
        }
        vector<int> ret;
        queue<Node*> bfs;
        for(auto &i: node->ind())
            ret.push_back(i);
        for(int i = 'A'; i <= 'Z'; i++){
            if(node->next(i))
                bfs.push(node->next(i));
        }
        while(!bfs.empty()){
            auto u = bfs.front();
            bfs.pop();
            for(auto &i: u->ind())
                ret.push_back(i);
            for(int i = 'A'; i <= 'Z'; i++){
                if(u->next(i))
                    bfs.push(u->next(i));
            }
        }
        return ret;
    }
};
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> dict, string pat) {
        // code here
        Trie trie;
        for(int i = 0; i < N; i++)
            trie.push(dict[i], i);
        vector<int> idxs = trie.search(pat);
        vector<string> ans;
        for(auto &i: idxs)
            ans.push_back(dict[i]);
        return ans.empty() ? vector<string>{"-1"} : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends