class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto &c: s){
            if(c != '*')
                st.push(c);
            else
                st.pop();
        }
        string ret = "";
        while(st.size()){
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};