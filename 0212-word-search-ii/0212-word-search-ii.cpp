// #define cc c-'a'
class Node{
public:
    Node* link[26];
    string finalWord = "";
    Node* get(char c)   { return link[c-'a']; }
    void put(char c)    { link[c-'a'] = new Node(); }
    void set(string s)  { finalWord = s; }
};

class Solution {
public:
    int ds[5] = {0, -1, 0, 1, 0};
    int m, n;
    bool isValid(int i, int j){ return i >= 0 && j >= 0 && i < m && j < n; }
    Node* root = new Node();
    void add(vector<string>& words){
        int k = words.size();
        for(int i = 0; i < k; i++){
            Node* trav = root;
            for(int j = 0; j < words[i].size(); j++){
                if(!trav->get(words[i][j]))
                    trav->put(words[i][j]);
                trav = trav->get(words[i][j]);
            }
            trav->set(words[i]);
        }
    }
    void dfs(vector<vector<char>> &board, int i, int j, Node* node, vector<string> &ans){
        char ch = board[i][j];
        if(ch == '#' || !node->get(ch))
            return;
        node = node->get(ch);
        if(node->finalWord.size() > 0){
            ans.push_back(node->finalWord);
            node->finalWord = "";
        }
        
        board[i][j] = '#'; //visited
        for(int k = 0; k < 4; k++){
            int r = i + ds[k], c = j + ds[k+1];
            if(isValid(r, c))
                dfs(board, r, c, node, ans);
        }
        board[i][j] = ch; //backtracking
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        add(words);
        vector<string> ans;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dfs(board, i, j, root, ans);
        return ans;
    }
};