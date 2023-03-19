struct Node{
    Node* link[26];
    bool end = false;
    bool containsKey(char c) { return link[c - 'a'] != nullptr; }
    Node* get(char c)        { return link[c - 'a'];  }
    void put(char c)         { link[c - 'a'] = new Node(); }
    void setEnd()            { end = true; }
    bool checkEnd()          { return end; }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* trav = root;
        for(int i = 0; i < word.size(); i++){
            if(!trav->containsKey(word[i]))
                trav->put(word[i]);
            trav = trav->get(word[i]);
        }
        trav->setEnd();
    }
    
    bool search(string word, int pos, Node* node){
        if(pos == word.size())
            return node->checkEnd();
        if(word[pos] != '.'){
            if(node->containsKey(word[pos])){
                node = node->get(word[pos]);
                return search(word, pos+1, node);
            }else return false;
        }else{ //if '.'
            for(int i = 'a'; i <= 'z'; i++){
                if(node->containsKey(i) && search(word, pos+1, node->get(i)))   
                    return true;
            }
            return false;
        }
    }
    bool search(string word) {
        // cout<<word<<endl;
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */