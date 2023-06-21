class Solution {
    vector<string> ans;
    string s;
    void f(int i, int lefts, string &curr, int rems){
        int n = s.size();
        if(rems < 0)
            return;
        if(i == n){
            if(lefts == 0)
                ans.push_back(curr);
            return;
        }
        int j = i;
        while(j < n && s[j] == s[i])
            j++;
        j--;
        if(s[i] == ')'){
            if(lefts > 0){
                curr.push_back(s[i]);
                f(i+1, lefts-1, curr, rems);
                curr.pop_back();
            }
            f(j+1, lefts, curr, rems-(j-i+1));
        }else if(s[i] == '('){
            curr.push_back(s[i]);
            f(i+1, lefts+1, curr, rems);
            curr.pop_back();
            f(j+1, lefts, curr, rems-(j-i+1));
        }else{
            curr.push_back(s[i]);
            f(i+1, lefts, curr, rems);
            curr.pop_back();
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        int rems = 0, lefts = 0;
        for(int i = 0; i < s.size(); i++){
            lefts += (s[i] == '(');
            if(s[i] == ')'){
                if(lefts == 0)
                    rems++;
                else lefts--;
            }
        }
        rems += lefts;
        string curr = "";
        f(0, 0, curr, rems);
        return ans;
    }
};