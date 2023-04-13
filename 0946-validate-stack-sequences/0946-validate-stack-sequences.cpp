class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        pushed.push_back(-1);
        stack<int> st;
        st.push(pushed[0]);
        int popind = 0, pushind = 1;
        while(st.size() && popind < popped.size() && pushind < pushed.size()){
            if(st.top() == popped[popind]){
                st.pop();
                popind++;
            }else{
                st.push(pushed[pushind++]);
            }
            if(st.empty()){
                if(pushind == pushed.size()-1 && popind == popped.size())
                    return true;
                else
                    st.push(pushed[pushind++]);
            }
        }
        return false;
    }
};