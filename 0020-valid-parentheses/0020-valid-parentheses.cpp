class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> brac;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '['){
                brac.push(s[i]);
            }else{
                if(brac.empty())
                    return false;
                else{
                    if( (s[i] == ')' and brac.top() != '(') or
                        (s[i] == '}' and brac.top() != '{') or
                        (s[i] == ']' and brac.top() != '[') )
                        return false;
                    else brac.pop();
                }
            }
        }
        if(brac.empty())
            return true;
        else return false;
    }
};