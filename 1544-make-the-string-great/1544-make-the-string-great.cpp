class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        while((n = s.size()) > 1){
            bool ok = false;
            for(int i = 0; i < n-1; i++){
                if(abs(s[i+1] - s[i]) == 'a' - 'A'){
                    s = s.substr(0, i) + s.substr(i+2);
                    ok = true;
                    break;
                }
            }
            if(!ok)
                break;
        }
        return s;
    }
};