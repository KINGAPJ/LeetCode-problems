class Solution {
    pair<int, int> maxmin(int frq[]){
        int maxx = 1, minn = 501;
        for(int i = 0; i < 26; i++){
            if(frq[i] > 0)
                maxx = max(frq[i], maxx);
            if(frq[i] > 0)
                minn = min(frq[i], minn);
        }
        return {maxx, minn};
    }
public:
    int beautySum(string s) {
        int frq[26] = {0}, ans = 0, n = s.size();
        for(int i = 0; i < n; i++){
            memset(frq, 0, sizeof(frq));
            for(int j = i; j < n; j++){
                frq[s[j]-'a']++;
                auto u = maxmin(frq);
                ans += u.first - u.second;
            }
        }
        return ans;
    }
};