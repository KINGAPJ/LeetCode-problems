class cmp{
public:
    bool operator()(pair<int, string> a, pair<int, string> b){
        if(a.first > b.first){
            return true;
        }else if(a.first == b.first){
            return a.second <= b.second;
        }else return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frq;
        for(auto &i: words)
            frq[i]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for(auto &i: frq){
            pq.push({i.second, i.first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<string> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};