class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";
        for(auto &i: word1)
            for(auto &j: i)
                s1.push_back(j);
        for(auto &i: word2)
            for(auto &j: i)
                s2.push_back(j);
        return s1 == s2;
    }
};