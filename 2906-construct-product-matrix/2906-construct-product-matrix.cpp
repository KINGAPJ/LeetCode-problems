#define ll long long
class Solution {
    ll mod = 12345;
    ll gcdExtended(ll a, ll b, ll &x, ll &y){
        //yields x, y such that ax + by = gcd(a, b)
        if(a == 0){
            x = 0;
            y = 1;    
            return b;
        }
        ll x1, y1;
        ll gcd = gcdExtended(b%a, a, x1, y1);
        x = y1 - (b/a) * x1;
        y = x1;
        return gcd;
    }

    ll modInv(ll a, ll m){
        ll x, y;
        ll gcd = gcdExtended(a, m, x, y);
        if(gcd != 1)
            return 0; //0 means inverse doesnt exist.. a.0 can never be 1 under modulo m
        return (x % m + m) % m; // to handle negative x
    }
    
    ll mul(ll x, ll n){
        x%=mod;
        ll ret = 1;
        while(n>0){
            if(n&1)
                ret = (x*ret)%mod;
            x = (x*x)%mod;
            n>>=1;
        }
        return ret;
    }
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> occ (n, vector<vector<int>>(m, vector<int>(3, 0))); //823, 3, 5
        vector<int> total(3);
        ll totprod = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int num = grid[i][j];
                int cnt823 = 0, cnt3 = 0, cnt5 = 0;
                while(num % 823 == 0){
                    num /= 823;
                    cnt823++;
                }
                while(num % 3 == 0){
                    num /= 3;
                    cnt3++;
                }
                while(num % 5 == 0){
                    num /= 5;
                    cnt5++;
                }
                occ[i][j] = {cnt823, cnt3, cnt5};
                total[0] += cnt823;
                total[1] += cnt3;
                total[2] += cnt5;
                totprod = (totprod * num) % 12345;
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int e823 = total[0] - occ[i][j][0];
                int e3 = total[1] - occ[i][j][1];
                int e5 = total[2] - occ[i][j][2];
                if(min({e823, e3, e5}) >= 1){
                    ans[i][j] = 0;
                }else{
                    // ll num = ((((ll) (pow(823, e823) * pow(3, e3) * pow(5, e5))) % 12345) * totprod) % 12345;
                    ll num = (((((mul(823, e823) * mul(3, e3)) % 12345) * mul(5, e5)) % 12345 ) * totprod) % 12345;
                    ll curr = grid[i][j];
                    while(curr % 823 == 0){
                        curr /= 823;
                    }
                    while(curr % 3 == 0){
                        curr /= 3;
                    }
                    while(curr % 5 == 0){
                        curr /= 5;
                    }
                    ll inv = modInv(curr, 12345);
                    ans[i][j] = (num * inv) % 12345;
                }
            }
        }
        return ans;
    }
};