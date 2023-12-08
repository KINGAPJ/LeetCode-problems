class Solution {
    const int mod = 1e9 + 7;
public:
    int numberOfWays(string corridor) {
        int ss = 0, n = corridor.size();
        for(auto &i: corridor)
            ss += i == 'S';
        if(ss & 1 || ss == 0)
            return 0;
        bool start = true;
        int currBeg = -1;
        vector<pair<int, int>> sections;
        for(int i = 0; i < n; i++){
            if(corridor[i] == 'S'){
                if(start)
                    currBeg = i;
                else
                    sections.push_back({currBeg, i});
                start = !start;
            }
        }
        long long ans = 1;
        for(int i = 0; i < sections.size()-1; i++)
            ans = (ans * (sections[i+1].first - sections[i].second)) % mod;
        return ans;
    }
};