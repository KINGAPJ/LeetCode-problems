class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 1, curr = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] < curr+1)
                curr = arr[i];
            else
                curr++;
            ans = max(ans, curr);
        }
        return ans;
    }
};