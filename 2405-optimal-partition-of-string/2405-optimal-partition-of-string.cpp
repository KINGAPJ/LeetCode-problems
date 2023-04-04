class Solution {
public:
    int partitionString(string s) {
        int currmask = 0, ans = 1;
        for(int i = 0; i < s.size(); i++){
            if(currmask & (1<<(s[i]-'a'))){
                currmask = (1<<(s[i]-'a'));
                ans++;
            }else{
                currmask |= (1<<(s[i]-'a'));
            }
        }
        return ans;
    }
};