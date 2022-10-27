class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(auto &i: tasks)
            mp[i]++;
        int ans = 0;
        for(auto &i: mp){
            if(i.second == 1)
                return -1;
            ans += 2 * (i.second / 6);
            int check = i.second % 6;
            if(check >= 1 && check <= 3)
                ans += 1;
            else if(check == 4 || check == 5)
                ans += 2;
        }
        return ans;
    }
};