class Solution {
    const int mod = 1e9 + 7;
public:
    int countHomogenous(string s) {
        long long ans = 0, n = s.size(), currLen = 1;
        char curr = s[0];
        for(int i = 1; i <= n; i++){ // == n is end char after last char, which wont be equal to letters
            if(s[i] == curr)
                currLen++;
            else{
                long long multiplier = currLen+1;
                if(currLen & 1)
                    multiplier >>= 1;
                else
                    currLen >>= 1;
                ans = (ans + (currLen * multiplier) % mod) % mod;
                currLen = 1;
                curr = s[i];
            }
        }
        return ans;
    }
};