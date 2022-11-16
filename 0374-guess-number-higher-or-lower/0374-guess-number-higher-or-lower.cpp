/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(n == 1)
            return 1;
        int pick, l = 1, h = n;
        while(l <= h){
            pick = l + (h-l)/2;
            int g = guess(pick);
            if(g == 0)
                return pick;
            else if (g < 0)
                h = pick - 1;
            else l = pick + 1;
        }
        return -1;
    }
};