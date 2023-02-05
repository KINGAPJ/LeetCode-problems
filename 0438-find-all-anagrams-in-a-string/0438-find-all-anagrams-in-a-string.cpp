class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if(m > n)
            return {};
        vector<int> ns(26), pm(26), ans;
        for(int i = 0; i < m; i++)
            pm[p[i]-'a']++;
        for(int i = 0; i < m; i++)
            ns[s[i]-'a']++;
        if(pm == ns)
            ans.push_back(0);
        for(int i = m; i < n; i++){
            ns[s[i]-'a']++;
            ns[s[i-m]-'a']--;
            if(ns == pm)
                ans.push_back(i-m+1);
        }
        return ans;
    }
};