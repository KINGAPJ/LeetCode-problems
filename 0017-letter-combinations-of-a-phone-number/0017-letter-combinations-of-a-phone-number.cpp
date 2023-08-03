class Solution {
public:
    vector<vector<char>> conv = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> ans;
    void comb(string ltrs, string& dig, int i){
        if(i == dig.size()){
            ans.push_back(ltrs);
            return;
        }
        for(auto x: conv[dig[i] - '0']){
            ltrs.push_back(x);
            comb(ltrs, dig, i+1);
            ltrs.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        string ltr = "";
        comb(ltr, digits, 0);
        return ans;
    }
};