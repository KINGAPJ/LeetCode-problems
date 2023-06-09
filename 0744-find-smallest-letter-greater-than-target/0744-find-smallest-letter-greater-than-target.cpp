class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = (int) letters.size()-1;
        int mid = hi, ans = hi;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            if(target < letters[mid]){
                ans = min(ans, mid);
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        if(target >= letters[ans])
            return letters.front();
        return letters[ans];
    }
};