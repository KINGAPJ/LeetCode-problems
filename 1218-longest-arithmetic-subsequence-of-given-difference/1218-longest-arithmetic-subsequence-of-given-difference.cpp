class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int n = arr.size(), ans = 1;
        for(int i = 0; i < n; i++){
            if(mp.count(arr[i]-difference)){
                mp[arr[i]] = mp[arr[i]-difference]+1;
                ans = max(ans, mp[arr[i]]);
            }else{
                mp[arr[i]] = 1;
            }
        }
        return ans;
    }
};