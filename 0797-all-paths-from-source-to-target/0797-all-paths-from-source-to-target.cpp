class Solution {
public:
    //any node will end to a dead end keep on going
    vector<vector<int>> ans;
    void dfs(int curr, vector<int>& nums, int n, vector<vector<int>> &graph){
        if(curr == n-1){
            ans.push_back(nums); //got n - 1
            return;
        }else if(graph[curr].size() == 0)
            return; //dead end
        for(auto &i: graph[curr]){
            nums.push_back(i);
            dfs(i, nums, n, graph);
            nums.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ret = {0};
        dfs(0, ret, n, graph);
        return ans;
    }
};