class Solution {
public:
    bool isPalindrome(int x) {
        string xxx = to_string(x);
        string triple_x = xxx;
        reverse(xxx.begin(), xxx.end());
        return xxx == triple_x;
    }
};