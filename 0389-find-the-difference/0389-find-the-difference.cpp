class Solution {
public:
    char findTheDifference(string s, string t) {
        int frq1[26] = {0}, frq2[26] = {0};
        for(int i = 0; i < s.size(); i++)
            frq1[s[i]-'a']++;
        for(int i = 0; i < t.size(); i++)
            frq2[t[i]-'a']++;
        for(int i = 0; i < 26; i++)
            if(frq1[i] != frq2[i])
                return i+'a';
        return ' ';
    }
};