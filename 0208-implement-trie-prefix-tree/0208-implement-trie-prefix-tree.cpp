class TrieNode{
    TrieNode* letters[26];
    bool endWord = false;
public:
    TrieNode* next(char c){return letters[c-'a'];}
    bool end(){return endWord;}
    void set(char c){letters[c-'a'] = new TrieNode();}
    void markEnd(){endWord = true;}
};
class Trie {
    TrieNode* root;
public:
    Trie() {root = new TrieNode();}
    void insert(string word) {
        TrieNode* node = root;
        for(auto &i: word){
            if(!node->next(i))
                node->set(i);
            node = node->next(i);
        }
        node->markEnd();
    }
    bool search(string word) {
        TrieNode* node = root;
        for(auto &i: word){
            if(!node->next(i))
                return false;
            node = node->next(i);
        }
        return node->end();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto &i: prefix){
            if(!node->next(i))
                return false;
            node = node->next(i);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */