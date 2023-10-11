class Solution {
public:
    /*
           p t y u i u y o p
           p t u k k u
           p t u k k k u r
             l l        r  r
           
           iterate over all indices and check for a given i if s[i+1] = s[i], increment right
           
        
    */
    string longestPalindrome(string s) {
        int n = s.size();
        int start_ind = 0, longest_length = 1, l, r;
        for(int i = 0; i < n; i++){
            r = i;
            while(r < n && s[i] == s[r])
                r++;
            l = i - 1;
            while(l >= 0 and s[l] == s[r]){
                l--, r++;
            }
            int length = r - l - 1;
            if(length > longest_length){
                start_ind = l + 1;
                longest_length = length;
            }
        }
        return string(s.begin()+start_ind, s.begin()+start_ind+longest_length);
    }
};