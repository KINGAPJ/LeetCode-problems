class Solution {
public:
    bool isv(char c){return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';}
    int maxVowels(string s, int k) {
        int maxv = 0, maxx = 0, n = s.size();
        for(int i = 0; i < k; i++){
            maxx += isv(s[i]);
        }
        maxv = max(maxv, maxx);
        for(int i = k; i < n; i++){
            maxx += isv(s[i]);
            maxx -= isv(s[i-k]);
            maxv = max(maxv, maxx);
        }
        return maxv;
    }
};