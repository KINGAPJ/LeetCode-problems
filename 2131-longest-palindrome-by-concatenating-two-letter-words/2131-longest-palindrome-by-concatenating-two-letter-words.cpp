class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        bool center = false;
        unordered_map<string, int> mp;
        for (auto &i : words)
            mp[i]++;
        for (auto &i : mp) {
            string word = i.first;
            int cnt = i.second;
            if (word[0] == word[1]) {
                if (cnt % 2 == 0) {
                    ans += cnt;
                } else {
                    ans += cnt - 1;
                    center = true;
                }
            } else if (word[0] < word[1] && mp.count({word[1], word[0]})) {
                ans += 2 * min(cnt, mp[{word[1], word[0]}]);
            }
        }
        if (center)
            ans++;
        return 2 * ans;
    }
};