class Solution {
public:
    /*
        a k-digit no repeated number can be formed in 
            s[k] = (10-(k-1))*s[k-1] ways..
        let f(i, j, k) represent the number of non repeated numbers
            formed by i digits and >= j and <= k
        now f(i+1, 10*j, 10*k + 9) = (10 - i) * f(i, j, k) 
        to find the number of non repeating numbers less than equal to n,
            we follow according the example:
        n = 75331..
        
        Part 1: same digits as n
        
        find f(1, 1, 7) which is 7..
        find f(2, 10, 75) which is f(2, 10, 79) - |{76, 78, 79}| = 9*7 - 3 = 60
        find f(3, 100, 753)..
        ..   f(5, 10000, 75331)..
        
        Part 2: less digits as n
        
        and finally find f(1, 1, 9) + f(2, 10, 99) + ... + f(4, 1000, 9999)
            to get the total number of numbers less than 10000 following the
            required criteria.
        
        now just n - the sum of these 2 parts yields the required answer
    */
    int numDupDigitsAtMostN(int n) {
        if(n < 11)
            return 0;
        int k = 0; //number of digits
        for(int i = n; i > 0; i/=10)
            k++;
        vector<int> digits(k); //the digits in the number stored in an array
        for(int i = 0, j = n; i < k; i++, j/=10)
            digits[k-1-i] = j%10; //assigning the digits to their positions
        
        int cnt[10] = {0};
        vector<int> part1_arr(k);
        bool dup = false;
        for(int i = 0; i < k; i++){
            part1_arr[i] = (i == 0) ? 9 : (10-i) * part1_arr[i-1];
            if(!dup){ //if only there are no duplicates 
                //then there is scope of minussing after multiplying in the recursion step
                //else we dont need to do anything
                
                int diff = 0; //calculating the difference after multiplying
                for(int j = digits[i]+1; j < 10; j++)
                    diff += (cnt[j] == 0); 
                //minus those which arent repeated in the digits formed yet
                //    and also are greater than last digit but less than 
                //    last digit being 9
                
                part1_arr[i] -= diff;
                cnt[digits[i]]++;
                if(cnt[digits[i]] > 1)
                    dup = true;
            }
        }
        
        int part2 = 0;
        vector<int> part2_arr(k-1);
        for(int i = 0; i < k-1; i++){
            part2_arr[i] = (i == 0) ? 9 : (10-i) * part2_arr[i-1];
            part2 += part2_arr[i];
        }
        
        return n - (part1_arr[k-1] + part2);
    }
};