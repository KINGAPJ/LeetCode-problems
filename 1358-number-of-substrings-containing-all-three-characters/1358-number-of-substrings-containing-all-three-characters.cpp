class Solution {
public:
    int numberOfSubstrings(string s) {
        int abc[3] = {0}, j = 0, n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            abc[s[i]-'a']++;
            if(abc[0] && abc[1] && abc[2]){
                int temp = 0;
                while(j < i && (abc[0] && abc[1] && abc[2])){
                    abc[s[j]-'a']--;
                    j++;
                    temp++;
                }
                ans += temp * (n-i);
            }
        }
        return ans;
    }
};