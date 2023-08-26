class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [&](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        int curr = INT_MIN, ans = 0;
        for(int i = 0; i < pairs.size(); i++){
            if(pairs[i][0] > curr){
                ans++, curr = pairs[i][1];
            }
        }
        return ans;
    }
};