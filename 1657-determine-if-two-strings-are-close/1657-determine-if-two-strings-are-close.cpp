class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_multiset<int> frqs1, frqs2;
        unordered_map<char, int> frq1, frq2;
        for(auto &i: word1)
            frq1[i]++;
        for(auto &i: word2)
            frq2[i]++;
        for(char i = 'a'; i <= 'z'; i++){
            if(frq1.count(i) != frq2.count(i))
                return false;
        }
        for(auto &i: frq1)
            frqs1.insert(i.second);
        for(auto &i: frq2)
            frqs2.insert(i.second);
        return (frqs1 == frqs2);
    }
};