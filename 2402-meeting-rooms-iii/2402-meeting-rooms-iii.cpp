class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> rooms(n);
        set<int> unocc;
        for(int i = 0; i < n; i++)
            unocc.insert(i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for(auto &i: meetings){
            while(pq.size() && pq.top().first <= i[0]){
                unocc.insert(pq.top().second);
                pq.pop();
            }
            if(pq.size() < n){
                pq.push({i[1], *unocc.begin()});
                rooms[*unocc.begin()]++;
                unocc.erase(unocc.begin());
                continue;
            }
            auto u = pq.top();
            long long earFin = u.first;
            int room = u.second;
            pq.pop();
            unocc.insert(room);
            pq.push({earFin+i[1]-i[0], room});
            rooms[room]++;
            unocc.erase(room);
        }
        int ans = -1, maxi = 0;
        for(int i = 0; i < n; i++){
            if(rooms[i] > maxi){
                maxi = rooms[i];
                ans = i;
            }
        }
        return ans;
    }
};