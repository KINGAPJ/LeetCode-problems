class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dictionary(words.begin(), words.end());
        vector<string> answer;
        for (const string& word : words) {
            const int length = word.length();
            vector<bool> dp(length + 1);
            dp[0] = true;
            for (int i = 1; i <= length; ++i) {
                for (int j = (i == length ? 1 : 0); !dp[i] && j < i; ++j) {
                    dp[i] = dp[j] && dictionary.count(word.substr(j, i - j));
                }
            }
            if (dp[length]) {
                answer.push_back(word);
            }
        }
        return answer;
    }
};


/*class Node{
    vector<Node*> ls(26);
    bool end = false;
public:
    Node* next(char c){return ls[c-'a'];}
    void set(char c){ls[c-'a'] = new Node();}
    void word(){end = true;}
    bool check(){return end;}
};
class Trie{
    Node* root;
public:
    Trie(){root = new Node();}
    void insert(string word){
        Node* node = root;
        for(auto &c: word){
            if(!node->next(c))
                node->set(c);
            node = node->next(c);
        }
        node->word();
    }
    bool check(string &word, int i){
        Node* node = root;
        bool ret = false;
        if(i == word.size())
            return true;
        for(int j = i; j < word.size(); j++){
            if(node->check()){
                ret |= check(word, j+1);
            }
            if(node->next(word[j])){
                node = node->next(word[j]);
            }
        }
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
    }
};
*/