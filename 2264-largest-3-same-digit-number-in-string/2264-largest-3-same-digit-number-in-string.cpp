class Solution {
public:
    string largestGoodInteger(string num) {
        int best = -1;
        for(int i = 0; i < num.size() - 2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2])
                best = max(best, num[i]-'0');
        }
        return best == -1 ? "" : string(3, best+'0');
    }
};