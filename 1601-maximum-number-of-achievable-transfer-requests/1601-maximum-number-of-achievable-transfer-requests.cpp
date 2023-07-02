class Solution {
    vector<vector<int>> req;
    vector<int> deg;
    int ans = 0;
    void f(int i, int rqsts){
        int m = req.size();
        if(i == m){
            bool valid = true;
            for(int x = 0; x < deg.size(); x++){
                // cout<<deg[x]<<' ';
                if(deg[x] != 0){
                    valid = false;
                }
            }
            // cout<<endl;
            if(valid)
                ans = max(ans, rqsts);
            return;
        }
        deg[req[i][0]]--; deg[req[i][1]]++;
        f(i+1, rqsts+1);
        deg[req[i][0]]++; deg[req[i][1]]--;
        f(i+1, rqsts);
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        req = requests;
        int m = requests.size();
        deg = vector<int>(n);
        f(0, 0);
        return ans;
    }
};