class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int nums_k = INT_MIN;
        stack<int> st;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] < nums_k)
                return true;
            while(!st.empty() && nums[i] > st.top()){
                nums_k = st.top(); st.pop();
            }
            int nums_j = nums[i];
            st.push(nums_j);
        }
        return false;
    }
};