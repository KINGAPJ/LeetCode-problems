class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> ord;
        for(int i = 0; i < 26; i++)
            ord[order[i]] = i;
        for(int i = 1; i < words.size(); i++){
            string w1 = words[i-1], w2 = words[i];
            int ind = 0;
            int sz = min(w1.size(), w2.size());
            while(ind < sz){
                if(ord[w1[ind]] > ord[w2[ind]])
                    return false;
                else if(ord[w1[ind]] < ord[w2[ind]])
                    break;
                ind++;
            }
            if(ind == sz && w1[ind-1] == w2[ind-1]){
                if(w1.size() > w2.size())
                    return false;
            }
        }
        return true;
    }
};