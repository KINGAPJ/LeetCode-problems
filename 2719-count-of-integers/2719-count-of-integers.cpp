#define ll long long
ll dp[23][2][401];
const long mod = 1e9 + 7;
class Solution {
public:
    ll _s(ll a, ll b){
        ll m = mod;
        return (a%m-b%m+m)%m;
    }
    ll solve(int i, bool t, int sum, int tar, string &num){
        int len = num.size();
        if(i == len){
            if(sum <= tar)
                return 1;
            else return 0;
        }
        if(dp[i][t][sum] != -1)
            return dp[i][t][sum];
        ll ans = 0;
        bool nt;
        int nsum;
        for(char d = '0'; d <= '9'; d++){
            if(!t && d > num[i])
                break;
            nt = t || d < num[i];
            nsum = (sum + (d - '0'))%mod;
            ans = (ans + solve(i+1, nt, nsum, tar, num))%mod;
        }
        return dp[i][t][sum] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        // ll n = stoll(num1);
        // num1 = to_string(n-1);
        reverse(num1.begin(), num1.end());
        int bo = 0;
        for(int i = 0; i < num1.size(); i++){
            if(num1[i] == '0'){
                bo = 1;
                num1[i] = '9';
            }else{
                num1[i]--;
                break;
            }
        }
        if(num1.back() == '0')
            num1.pop_back();
        if(num1.size() == 0)
            num1 = "0";
        reverse(num1.begin(), num1.end());
        min_sum--;
        memset(dp, -1, sizeof(dp));
        ll n2d2 = solve(0, 0, 0, max_sum, num2);
        memset(dp, -1, sizeof(dp));
        ll n2d1 = solve(0, 0, 0, min_sum, num2);
        memset(dp, -1, sizeof(dp));
        ll n1d2 = solve(0, 0, 0, max_sum, num1);
        memset(dp, -1, sizeof(dp));
        ll n1d1 = solve(0, 0, 0, min_sum, num1);
        // cout<<num1<<' '<<num2<<' '<<min_sum<<' '<<max_sum<<'\n';
        // cout<<n2d2<<' '<<n2d1<<' '<<n1d2<<' '<<n1d1<<'\n';
        return _s(_s(n2d2, n2d1), _s(n1d2, n1d1));
    }
};