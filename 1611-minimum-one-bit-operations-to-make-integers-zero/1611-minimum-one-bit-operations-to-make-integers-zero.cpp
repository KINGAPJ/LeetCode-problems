class Solution {
    string toBin(int n) { 
        string s = bitset<32>(n).to_string(); 
        auto loc = s.find('1');
        if(loc != string::npos) 
            return s.substr(loc); 
        return "0"; 
    } 
public:
    int minimumOneBitOperations(int n) {
        string binRep = toBin(n);
        int ans = 0, sz = binRep.size();
        for(int i = sz-1; i >= 0; i--){
            if(binRep[i] == '1')
                ans = (1<<(sz-i)) - 1 - ans;
        }
        return ans;
    }
};