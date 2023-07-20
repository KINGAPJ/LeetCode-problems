class Solution {
    const int mod = 1e9 + 7;
public:
    int longestDecomposition(string text) {
        int n = text.size();
        vector<long> powers(n+1, 1);
        vector<long> prefhash(n);
        long prime = 31; 
        for(long i = 1; i <= n; i++)
            powers[i] = (powers[i-1]*prime)%mod;
        prefhash[0] = text[0]-'a'+1;
        for(long i = 1; i < n; i++)
            prefhash[i] = (prefhash[i-1] + (text[i]-'a'+1)*powers[i])%mod;
        int maxlen = n/2, ans = 0, st = 0;
        maxlen++;
        for(int len = 1; len <= maxlen+1; len++){
            int l1 = st, r1= st+len-1, l2=n-st-len, r2=l2+len-1;
            if(l2 <= r1){
                ans++;
                break;
            }
            long compute = (prefhash[r1]- ((l1-1)>=0 ? prefhash[l1-1]: 0)+mod)%mod;
            compute = (compute * powers[n-st-1])%mod;

            long compute2 = (prefhash[r2]-((l2-1)>=0 ? prefhash[l2-1]: 0)+mod)%mod;
            compute2 = (compute2 * powers[n-l2-1])%mod;

            if(compute == compute2){
                ans += 2;
                st += len;
                len = 0;
                if(r1+1 == l2)
                    break;
            }
        }
        return ans;
    }
};