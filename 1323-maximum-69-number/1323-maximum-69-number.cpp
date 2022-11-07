class Solution {
public:
    int maximum69Number (int n) {
        int N = n, cnt = 0;
        while(N){
            N /= 10;
            cnt++;
        }
        for(int i = cnt-1; i >= 0; i--){
            if((n / (int) pow(10, i))%10 == 6){
                n += 3*pow(10, i);
                return n;
            }
        }
        return n;
    }
};