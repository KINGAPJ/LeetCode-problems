class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        int n = s.size();
        int i = n - 1;
        while(i >= 0){
            if(s[i] == ' '){
                i--;
                continue;
            }
            int last = i;
            while(i >= 0 && s[i] != ' ')
                i--;
            int start = i + 1;
            for(int j = start; j <= last; j++)
                ret.push_back(s[j]);
            ret.push_back(' ');
        }
        if(ret[ret.size() - 1] == ' ')
            ret.pop_back();
        return ret;
    }
};