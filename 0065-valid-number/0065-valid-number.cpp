class Solution {
public:
    bool isValid(string s, int state) {
        int n = s.size();
        for(int i = 0;i<n;i++) {
            if(state == 1) {
                if(isSign(s[i])) {
                    state = 2;
                } else if(isdigit(s[i])) {
                    state = 4;
                } else if(s[i] == '.') {
                    state = 3;
                } else return false;
            } else if(state == 2) {
                if(isdigit(s[i])) {
                    state = 4;
                } else if(s[i] == '.') {
                    state = 3;
                } else return false;
            } else if(state == 3) {
                if(isdigit(s[i])) {
                    state = 9;
                } else return false;
            } else if(state == 4) {
                if(isdigit(s[i])) {
                    
                } else if(s[i] == '.') {
                    state = 5;
                } else if(isE(s[i])) {
                    state = 10;
                } else return false;
            } else if(state == 5) {
                if(isdigit(s[i])) {
                    
                } else if(isE(s[i])) {
                    state = 10;
                } else return false;
            } else if(state == 6) {
                if(isSign(s[i])) {
                    state = 7;
                } else if(isdigit(s[i])) {
                    state = 8;
                } else return false;
            } else if(state == 7) {
                if(isdigit(s[i])) {
                    state = 8;
                } else return false;
            } else if(state == 8) {
                if(isdigit(s[i])) {
                    
                } else if(isE(s[i])) {
                    state = 10;
                } else return false;
            } else if(state == 9) {
                if(isdigit(s[i])) {
                    
                } else if(isE(s[i])) {
                    state = 10;
                } else return false;
            } else if(state == 10) {
                if(isSign(s[i])) {
                    state = 11;
                } else if(isdigit(s[i])) {
                    state = 12;
                } else return false;
            } else if(state == 11) {
                if(isdigit(s[i])) {
                    state = 12;
                } else return false;
            } else if(state == 12) {
                if(isdigit(s[i])) {
                    
                } else return false;
            }
           //  cout<<state<<" "<<i<<endl;
        }
        return state == 4 || state == 5 || state == 8 || state == 9 || state == 12;
    }
    
    bool isNumber(string s) {
        bool isDecimal = isValid(s,1);
        bool isInteger = isValid(s,6);
        return isDecimal || isInteger;
    }
    
    bool isSign(char c) {
        return c == '+' || c == '-';
    }
    
    bool isE(char c ) {
        return c == 'e' || c == 'E';
    }
};