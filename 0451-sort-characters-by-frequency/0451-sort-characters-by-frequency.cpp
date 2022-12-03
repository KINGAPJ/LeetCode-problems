class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frq;
        for(auto &i: s)
            frq[i]++;
        vector<pair<int, char>> sortfrq;
        for(auto &i: frq)
            sortfrq.push_back({i.second, i.first});
        sort(sortfrq.begin(), sortfrq.end());
        string res = "";
        for(auto i = sortfrq.rbegin(); i != sortfrq.rend(); i++)
            for(int j = 0; j < (*i).first; j++)
                res += (*i).second;
        return res;
    }
};