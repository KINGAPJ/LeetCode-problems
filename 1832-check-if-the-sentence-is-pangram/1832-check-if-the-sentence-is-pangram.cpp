class Solution {
public:
    bool checkIfPangram(string s) {
        int ch = 0;
        for(auto &i: s)
            ch |= (1<<(i-'a'));
        if(ch + 1 == (1 << 26))
            return true;
        return false;
    }
};