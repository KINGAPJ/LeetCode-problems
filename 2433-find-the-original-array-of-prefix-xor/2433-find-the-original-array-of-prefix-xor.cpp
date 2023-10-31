class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr;
        int curr = 0, n = pref.size();
        for(int i = 0; i < n; i++){
            arr.push_back(curr ^ pref[i]);
            curr ^= arr[i];
        }
        return arr;
    }
};