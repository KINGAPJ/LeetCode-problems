class Solution {
public:
    bool isv(char c){return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';}
    bool halvesAreAlike(string s) {
        int cn = 0;
        for(int i = 0; i < (s.size()>>1); i++)
            cn += (isv(tolower(s[i]))) ? 1 : 0;
        
        for(int i = s.size()/2; i < s.size(); i++)
            cn += (isv(tolower(s[i]))) ? -1 : 0;
        return cn == 0;
    }
};