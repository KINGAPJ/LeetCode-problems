class Solution {
    bool isVowel(char a){
        a = tolower(a);
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
    }
public:
    string sortVowels(string s) {
        vector<char> vowels;
        vector<int> inds;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                vowels.push_back(s[i]);
                inds.push_back(i);
            }
        }
        sort(vowels.begin(), vowels.end());
        for(int i = 0; i < inds.size(); i++)
            s[inds[i]] = vowels[i];
        return s;
    }
};