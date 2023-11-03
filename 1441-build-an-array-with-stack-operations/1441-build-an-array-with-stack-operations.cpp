class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int last = target.back(), targetInd = 0;
        vector<string> ans;
        for(int i = 1; i <= last && targetInd < target.size(); i++){
            ans.push_back("Push");
            if(i == target[targetInd])
                targetInd++;
            else
                ans.push_back("Pop");
        }
        return ans;
    }
};