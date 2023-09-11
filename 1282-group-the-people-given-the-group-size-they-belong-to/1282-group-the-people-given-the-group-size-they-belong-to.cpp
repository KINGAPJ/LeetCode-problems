class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> grps;
        int n = groupSizes.size();
        for(int i = 0; i < n; i++){
            grps[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto &i: grps){
            int numGrps = i.second.size()/i.first;
            int ind = 0;
            for(int j = 0; j < numGrps; j++){
                vector<int> temp;
                for(int k = 0; k < i.first; k++)
                    temp.push_back(i.second[ind++]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};