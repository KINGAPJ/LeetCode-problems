class Solution {
public:
    /*
        Monotonic Stack... push when greater(or lesser).. pop when lesser(or greater)
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> monotonic_st;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            while(!monotonic_st.empty() && 
                  temperatures[monotonic_st.top()] < temperatures[i]){
                int top = monotonic_st.top();
                monotonic_st.pop();
                ans[top] = i - top;
            }
            monotonic_st.push(i);
        }
        return ans;
    }
};