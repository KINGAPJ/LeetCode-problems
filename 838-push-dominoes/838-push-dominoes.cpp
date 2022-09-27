class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<int> indices(n+2);
        vector<char> symbols(n+2);
        int len = 1;
        indices[0] = -1;
        symbols[0] = 'L';
        for(int i = 0; i < n; i++){
            if(s[i] != '.'){
                indices[len] = i;
                symbols[len++] = s[i];
            }
        }
        indices[len] = n;
        symbols[len++] = 'R';
        string res = s;
        for(int index = 0; index < len-1; index++){
            int i = indices[index], j = indices[index+1];
            char x = symbols[index], y = symbols[index+1];
            char write;
            if(x == y){
                for(int k = i+1; k < j; k++)
                    res[k] = x;
            }else if(x > y){//RL
                for(int k = i+1; k < j; k++)
                    res[k] = k-i == j-k ? '.' : k-i < j-k ? 'R' : 'L';
            }
        }
        return res;
    }
};