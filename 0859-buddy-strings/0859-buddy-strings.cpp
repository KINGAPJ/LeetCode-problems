class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n < 2 || n != m)
            return false;
        if(s != goal){
            int firstDiff = -1;
            int seconDiff = -1;
            bool yes = false;
            for(int i = 0; i < n; i++){
                if(firstDiff == -1 && s[i] != goal[i]){
                    firstDiff = i;
                }else if(firstDiff != -1 && s[i] != goal[i]){
                    if(seconDiff == -1 && goal[i] == s[firstDiff] && s[i] == goal[firstDiff]){
                        yes = true;
                        seconDiff = i;
                    }else
                        return false;
                }
            }
            return yes;
        }else{
            map<int, int> frq;
            for(int i = 0; i < n; i++){
                if(frq[s[i]] == 1)
                    return true;
                frq[s[i]]++;
            }
            return false;
        }
    }
};