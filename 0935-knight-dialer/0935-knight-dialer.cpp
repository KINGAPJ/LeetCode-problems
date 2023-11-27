class Solution {
public:
    //iterative dp
    const int mod = 1e9 + 7;
    vector<vector<int>> neighbours = {
        {4, 6},    //0
        {6, 8},    //1
        {7, 9},    //2
        {4, 8},    //3
        {0, 3, 9}, //4
        {},        //5
        {0, 1, 7}, //6
        {2, 6},    //7
        {1, 3},    //8
        {2, 4}     //9
    };
    int knightDialer(int n) {
        if(n == 1)
            return 10;
        vector<vector<int>> tab(2, vector<int>(10));
        for(int i = 0; i < 10; i++){
            tab[0][i] = neighbours[i].size();
        }
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < 10; j++){
                tab[1][j] = 0;
                for(int k = 0; k < neighbours[j].size(); k++)
                    (tab[1][j] += (tab[0][neighbours[j][k]])) %= mod;
            }
            for(int j = 0; j < 10; j++)
                tab[0][j] = tab[1][j];
        }
        int ans = 0;
        for(int i = 0; i < 10; i++){
            (ans += tab[0][i]) %= mod;
        }
        return ans;
    }
};