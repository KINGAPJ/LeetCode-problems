class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //at max there can be only 2 majority elements
        int n = nums.size();
        int target = n/3;
        int cand1 = INT_MIN, cand2 = INT_MIN, cand1frq = 0, cand2frq = 0;
        // cout<<'\n';
        for(auto &i: nums){
            // cout<<cand1<<':'<<cand1frq<<' '<<cand2<<':'<<cand2frq<<'\n';
            if(i == cand1)
                cand1frq++;
            else if(i == cand2)
                cand2frq++;
            else if(cand1frq == 0){
                cand1frq++;
                cand1 = i;
            }else if(cand2frq == 0){
                cand2frq++;
                cand2 = i;
            }else{
                cand1frq--;
                cand2frq--;
            }
        }
        vector<int> ans;
        cand1frq = 0, cand2frq = 0;
        for(auto &i: nums){
            cand1frq += (i == cand1);
            cand2frq += (i == cand2);
        }
        if(cand1frq > target)
            ans.push_back(cand1);
        if(cand2frq > target)
            ans.push_back(cand2);
        return ans;
    }
};