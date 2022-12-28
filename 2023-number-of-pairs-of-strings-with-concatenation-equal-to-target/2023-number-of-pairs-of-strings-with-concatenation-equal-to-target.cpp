class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        unordered_map<string, int> meow;
        for(auto &i: nums)
            meow[i]++;
        for(auto &i: nums){
            auto r = mismatch(i.begin(), i.end(), target.begin());
            if(r.first == i.end()){
                string suffix = target.substr(r.second - target.begin());
                if(i == suffix)
                    ans += meow[suffix]-1;
                else
                    ans += meow[suffix];
            }
        }
        return ans;
    }
};