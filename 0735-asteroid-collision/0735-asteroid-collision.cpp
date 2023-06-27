class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(auto &i: asteroids){
            bool add = true;
            while(st.size() && st.top() > 0 && i < 0){
                if(st.top() < -i){
                    st.pop();
                    continue;
                }else if(st.top() == -i){
                    st.pop();
                }
                add = false;
                break;
            }
            if(add)
                st.push(i);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};