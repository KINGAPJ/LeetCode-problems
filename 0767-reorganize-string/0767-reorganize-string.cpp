class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        int frq[26] = {0};
        for(auto &i: s)
            frq[i-'a']++;
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i++)
            if(frq[i] > 0)
                pq.push({frq[i], i+'a'});
        string ret = string(n, '.');
        if(pq.top().first > (n+1)/2)
            return {};
        int alt = 0;
        while(!pq.empty()){
            auto u = pq.top(); pq.pop();
            int occ = u.first;
            while(occ--){
                ret[alt] = u.second;
                alt += 2;
                if(alt >= n)
                    alt = 1;
            }
        }
        return ret;
    }
};