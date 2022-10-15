class Solution {
    const static int N = 127;
//For all problem like this one, which we need to build some "group", I always try to build the first group, and leaving the rest as a subproblem and solve it by recursive.
    
    // dp[left][k] means the minimal coding size for substring 
    // s[left:] and removing at most k chars
    int dp[N][N];

    string str;
    int n;

    // get length of digit
    inline int xs(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }

    int solve(int left, int k) {
        if(k < 0) return N;  // invalid, return INF
        if(left >= n or n - left <= k) return 0;  // empty

        int& res = dp[left][k];
        if(res != -1) return res;
        res = N;

        int cnt[26] = {0};
        // we try to make s[left:j] (both inculded) as one group,
        // and all chars in this group should be the same.
        // so we must keep the most chars in this range and remove others
        // the range length is (j - left + 1)
        // and the number of chars we need to remove is (j - left + 1 - most)
        for(int j = left, most = 0; j < n; j++) {
            most = max(most, ++cnt[str[j] - 'a']);  // most = max(count(s[left:j])
            res = min(res, 1 + xs(most) + solve(j + 1, k - (j - left + 1 - most)));
        }
        return res;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        str = s;
        n = s.size();
        return solve(0, k);
    }
};
    //do a 0-1 knapsack on cost of compression for each consecutive faction and compression obtained
    //wrong approach as after deletion, two different factions can combine to make a bigger streak
    /*
    int dp(vector<int> &cost, vector<int> &comp, int k){
        int n = comp.size();
        vector<vector<int>> table(n+1, vector<int>(k+1));
        for(int i = 0; i <= n; i++){
            for(int w = 0; w <= k; w++){
                if(i == 0 || w == 0)
                    table[i][w] = 0;
                else if(cost[i-1] <= w)
                    table[i][w] = max(comp[i-1]+table[i-1][w-cost[i-1]], 
                                        table[i-1][w]);
                else
                    table[i][w] = table[i-1][w];
            }
        }
        return table[n][k];
    }
    int getLengthOfOptimalCompression(string s, int k) {
        vector<int> cost, comp;
        s.push_back('.');
        int n = s.size();
        char curr = s[0];
        int streak = 1, length = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == curr){
                streak++;
            }else{
                if(streak == 100){
                    if(k == 0)
                        return 4;
                    else if(k <= 90)
                        return 3;
                    else if(k <= 98)
                        return 2;
                    else if(k == 99)
                        return 1;
                    else return 0;
                }else if(streak >= 10){
                    length += 3;
                    cost.push_back(streak - 9);
                    comp.push_back(1);
                    cost.push_back(streak - 1);
                    comp.push_back(2);
                    cost.push_back(streak);
                    comp.push_back(3);
                }else if(streak >= 2){
                    length += 2;
                    cost.push_back(streak - 1);
                    comp.push_back(1);
                    cost.push_back(streak);
                    comp.push_back(2);
                }else if(streak == 1){
                    length += 1;
                    cost.push_back(streak);
                    comp.push_back(1);
                }
                streak = 1;
                curr = s[i];
            }
        }
        for(int i: cost){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i: comp){
            cout<<i<<" ";
        }
        cout<<endl;
        return length - dp(cost, comp, k);
    }
}; */