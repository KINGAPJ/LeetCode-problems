class Solution {
public:
    int addDigits(int num) {
        long curr = 0;
        while(num > 0){
            curr += num % 10;
            if(curr >= 10)
                curr -= 9;
            num /= 10;
        }
        return curr;
    }
};