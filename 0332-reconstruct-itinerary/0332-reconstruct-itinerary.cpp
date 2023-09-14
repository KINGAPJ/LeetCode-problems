class Solution {
public:
    
   
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> m;
    vector<string> ans;
    void dfs(string st)
    {
        while(!m[st].empty())
        {
            auto it=m[st].top();
            m[st].pop();
            dfs(it);
        }
        ans.push_back(st);
        
    }
    vector<string> findItinerary(vector<vector<string>>& a) {
        m.clear(); 
        for(auto i: a)
         {
             m[i[0]].push(i[1]);
         }
        ans.clear();
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};