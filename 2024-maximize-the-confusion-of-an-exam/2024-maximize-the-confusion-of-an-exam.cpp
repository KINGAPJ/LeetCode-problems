class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0, r = 0;
        int n = answerKey.size();
        int currK = 0, ans = k;
        while(r < n && currK < k){
            if(answerKey[r] == 'F')
                currK++;
            ans = max(ans, r-l+1);
            r++;
        }
        if(r == n)
            return n;
        while(r < n){
            currK += answerKey[r] == 'F';
            if(currK > k){
                while(l < r && currK > k){
                    currK -= answerKey[l] == 'F';
                    l++;
                }
            }else{
                ans = max(ans, r-l+1);
            }
            r++;
        }
        // cout<<ans<<'\n';
        l = 0, r = 0, currK = 0;
        while(r < n && currK < k){
            if(answerKey[r] == 'T')
                currK++;
            ans = max(ans, r-l+1);
            r++;
        }
        if(r == n)
            return n;
        while(r < n){
            currK += answerKey[r] == 'T';
            if(currK > k){
                while(l < r && currK > k){
                    currK -= answerKey[l] == 'T';
                    l++;
                }
            }else{
                ans = max(ans, r-l+1);
            }
            r++;
        }
        return ans;
    }
};