class Solution {
public:
    string breakPalindrome(string pal) {
        int n = pal.size();
        if(n == 1)
            return "";
        for(int i = 0; i < n; i++){
            if(pal[i] != 'a'){
                int l = i-1, r = i+1;
                while(l >= 0 && r < n && pal[l] == pal[r])
                    l--, r++;
                if(l != -1 || r != n){
                    pal[i] = 'a';
                    return pal;
                }
            }
        }
        pal[n-1] = 'b';
        return pal;
    }
};