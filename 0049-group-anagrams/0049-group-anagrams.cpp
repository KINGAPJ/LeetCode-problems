class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <multiset<char>, vector<string>> mp;
        vector<vector<string>> ret;
        for (int i=0; i<strs.size(); i++)
        {
            string s=strs[i];
            multiset <char> ms;
            for (auto is: s)
            {
                ms.insert(is);
            }
            mp[ms].push_back(s);
        }
        for (auto it: mp)
        {
            ret.push_back(it.second);
        }
        return ret;
    }
};