class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans;
        unordered_set<int> eve_ind;
        int evesum = 0;
        for(int i = 0; i < n; i++){
            if(!(nums[i] & 1)){
                eve_ind.insert(i);
                evesum += nums[i];
            }
        }
        for(auto &i: queries){
            if((nums[i[1]]+i[0]) & 1){
                if(eve_ind.count(i[1])){
                    evesum -= nums[i[1]];
                    eve_ind.erase(i[1]);
                }
            }else{
                if(!eve_ind.count(i[1])){
                    eve_ind.insert(i[1]);
                    evesum += (nums[i[1]] + i[0]);
                }else evesum += i[0];
            }
            ans.push_back(evesum);
            nums[i[1]] += i[0];
        }
        return ans;
    }
};