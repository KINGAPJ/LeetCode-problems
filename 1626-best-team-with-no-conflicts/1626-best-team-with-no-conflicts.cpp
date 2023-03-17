class Solution{
    vector<vector<int>> memo;
public:
    int dp(vector<vector<int>>& ageScore, int i, int prevSelected){
        int n = ageScore.size();
        if(i == n)
            return 0;
        if(memo[i][prevSelected] != -1)
            return memo[i][prevSelected];
        int ans = 0;
        if(prevSelected == n || 
           !(ageScore[prevSelected][0] < ageScore[i][0] &&
            ageScore[prevSelected][1] > ageScore[i][1])
          ){
            ans += ageScore[i][1] + dp(ageScore, i+1, i);
        }
        ans = max(ans, dp(ageScore, i+1, prevSelected));
        return memo[i][prevSelected] = ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages){
        int n = scores.size();
        vector<vector<int>> ageScore(n);
        memo = vector<vector<int>>(n, vector<int>(n+1, -1));
        for(int i = 0; i < n; i++)
            ageScore[i] = {ages[i], scores[i]};
        sort(ageScore.begin(), ageScore.end());
        return dp(ageScore, 0, n);
    }
};
// class Solution {
//     vector<int> memo;
// public:
//     int dp(vector<vector<int>>& ageScore, int i, vector<int>
//            // vector<vector<int>>& formedList){
//         int n = ageScore.size();
//         if(i == n)
//             return 0;
//         if(memo[i] != -1)
//             return memo[i];
//         int highestLowerAgeScore = 0, ans = 0;
//         // for(int j = 0; j < formedList.size() && formedList[j][0] < ageScore[i][0]; j++){
//         //     highestLowerAgeScore = max(highestLowerAgeScore, formedList[j][1]);
//         // }
//         cout<<i<<" "<<highestLowerAgeScore<<"\n";
//         for(auto &j: formedList)
//             cout<<j[0]<<':'<<j[1]<<' ';
//         cout<<'\n';
//         if(ageScore[i][1] >= highestLowerAgeScore){
//             formedList.push_back(ageScore[i]);
//             ans = ageScore[i][1] + dp(ageScore, i+1, formedList);
//             formedList.pop_back();
//         }
//         ans = max(ans, dp(ageScore, i+1, formedList));
//         return memo[i] = ans;
//     }
//     int bestTeamScore(vector<int>& scores, vector<int>& ages) {
//         int n = scores.size();
//         vector<vector<int>> ageScore(n), formedList;
//         for(int i = 0; i < n; i++){
//             ageScore[i] = {ages[i], scores[i]};
//         }
//         sort(ageScore.begin(), ageScore.end());
//         memo = vector<int>(n, -1);
//         return dp(ageScore, 0, formedList);
//     }
// };