class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
        if (n == 2){
            if (k == 1)
                return 0;
            if (k == 2)
                return 1;
        }
        if (k > pow(2, n - 2))
            return !kthGrammar(n - 1, k - pow(2, n - 2));
        else return kthGrammar(n - 1, k);
    }
};