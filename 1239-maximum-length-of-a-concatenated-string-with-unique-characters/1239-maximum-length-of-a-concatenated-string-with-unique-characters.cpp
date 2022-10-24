class Solution {
    vector<map<int, int>> memo;
public:
    int dp(vector<int> &bits, vector<string> &arr, int i, int lets){
        int n = bits.size();
        if(i >= n)
            return 0;
        if(memo[i].count(lets))
            return memo[i][lets];
        int curr = bits[i];
        if(curr == (1<<26) || (curr & lets) != 0){
            return memo[i][lets] = dp(bits, arr, i+1, lets);
        }else{
            int orred = lets | curr;
            int opt1 = arr[i].size() + dp(bits, arr, i+1, orred);
            int opt2 = dp(bits, arr, i+1, lets);
            return memo[i][lets] = max(opt1, opt2);
        }
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        memo = vector<map<int, int>>(n+1);
        vector<int> bits(n);
        int maxx = (1<<26);
        for(int i = 0; i < arr.size(); i++){
            int num = 0;
            for(int j = 0; j < arr[i].size(); j++){
                if(num & (1<<(arr[i][j]-'a'))){
                    num = maxx;
                    break;
                }else{
                    num |= 1<<(arr[i][j] - 'a');
                }
            }
            bits[i] = num;
        }
        return dp(bits, arr, 0, 0);
    }
};