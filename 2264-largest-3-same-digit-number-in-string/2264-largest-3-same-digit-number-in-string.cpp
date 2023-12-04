class Solution {
public:
    string largestGoodInteger(string num) {
        int best = -1;
        for(int i = 0; i < num.size() - 2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2])
                best = max(best, num[i]-'0');
        }
        if(best == -1)
            return "";
        string ret = string(3, 'x');
        fill(ret.begin(), ret.end(), best+'0');
        return ret;
    }
};