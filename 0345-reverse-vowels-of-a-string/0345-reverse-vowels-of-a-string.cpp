class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        vector<int> ind;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I'
              || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
                ind.push_back(i);
        }
        for(int i = 0; i < ind.size()/2; i++){
            swap(s[ind[i]], s[ind[ind.size()-1-i]]);
        }
        return s;
    }
};