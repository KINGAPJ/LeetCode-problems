class Solution {
public:
    unordered_map<int, int> map;
    int tribonacci(int n) {
        if(n<2) return n;
        if(n==2) return 1;
        if(map.find(n-1)==map.end()) map[n-1]=tribonacci(n-1);
        if(map.find(n-2)==map.end()) map[n-2]=tribonacci(n-2);
        if(map.find(n-3)==map.end()) map[n-3]=tribonacci(n-3);
        return map[n-1]+map[n-2]+map[n-3];
    }
};