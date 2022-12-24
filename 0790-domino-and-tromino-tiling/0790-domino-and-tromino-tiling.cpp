#define ll long long
const ll MOD = 1e9 + 7;
class Solution {
public:
    int numTilings(int N) {
        int T_prepre = 1, T_pre = 1;
        int T_up_pre = 0, T_down_pre = 0;

        for (int n = 2; n <= N; n++) {
            int T_cur = (int)((0L + T_prepre + T_pre + T_up_pre + T_down_pre) % MOD);
            int T_up_cur = (T_prepre + T_down_pre) % MOD;
            int T_down_cur = (T_prepre + T_up_pre) % MOD;

            T_prepre = T_pre;
            T_pre = T_cur;

            T_up_pre = T_up_cur;
            T_down_pre = T_down_cur;
        }

        return T_pre;
    }
};
/*
        //placing vertical block of 2;
        ret += dp(n-1, odd);
        //placing 2 horizontal blocks of 2;
        ret += dp(n-2, odd);
        //placing L of 3 in 4 ways;
        ret += 4*(dp(n-2, !odd));
        /*
            placing  .. or  ..   depending one which side  
                    ..       ..
            
            ret += dp(n-2, !odd);
            
            ll dp(ll n, bool odd){// odd is extra 0.5
        if(n <= 0)
            return 0;
        if(n <= 2)
            return n;
        ll ret = 0;
        if(odd == 0){
            /*
                placing    . and .. to stack on left
                          ..      .
            
            ret += 2*dp(n-2, !odd);
            //placing vertical block of 2;
            ret += dp(n-1, odd);
            //placing 2 horizontal blocks of 2;
            ret += dp(n-2, odd);
        }else{
            /*
                placing   .  or .. to stack on left to balance
                          ..    .
            
            ret += dp(n-2, !odd);
            //placing horizontal block of 2;
            ret += dp(n-1, odd);
        }
        return ret;
    }
*/