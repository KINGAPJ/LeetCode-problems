class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), i = 0, j = 0, ans = 0;
        unordered_map<char, int> locs, frq;
        while(i < n && j < n){
            frq[s[j]]++;
            if(frq[s[j]] == 2){
                int new_i = locs[s[j]]+1;
                for(int k = i; k < new_i; k++)
                    frq.erase(s[k]);
                i = new_i;
                frq[s[j]] = 1;
            }
            locs[s[j]] = j;
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};