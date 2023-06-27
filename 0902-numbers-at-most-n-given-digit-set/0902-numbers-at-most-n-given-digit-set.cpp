class Solution {
    vector<int> number;
    vector<string> digits;
    vector<vector<vector<int>>> dp;
    int f(int i, bool tight, bool ldg){
        int n = number.size();
        if(i == n)
            return 1;
        if(dp[i][tight][ldg] != -1)
            return dp[i][tight][ldg];
        int ans = 0;
        bool newtight = false;
        if(ldg)
            ans += f(i+1, false, ldg);
        int k = tight ? number[i] : 9;
        for(int j = 0; j < digits.size() && digits[j][0]-'0' <= k; j++){
            newtight = digits[j][0]-'0' == number[i] ? tight : false;
            ans += f(i+1, newtight, false);
        }
        return dp[i][tight][ldg] = ans;
    }
    void getDigits(int n){
        vector<int> dig;
        while(n){
            dig.push_back(n%10);
            n /= 10;
        }
        reverse(dig.begin(), dig.end());
        number = dig;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        getDigits(n);
        sort(digits.begin(), digits.end());
        this->digits = digits;
        int x = number.size();
        dp = vector(x+1, vector(2, vector<int>(2, -1)));
        return f(0, true, true)-1;
    }
};