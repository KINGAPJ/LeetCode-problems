class Solution {
public:
    /*
    1 10 2 5
    1 5 2 10
    1 5 3 7 2 10
    1 8 3 7 3 10
    3 3 5 0 4
    
    for applying dp we only need to go one by one and check if we bought or
    sold the 1st or 2nd stock that day
    */
    int maxProfit(vector<int>& prices){
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(auto &i: prices){
            //go from last operation to first operation
            release2 = max(release2, hold2+i);
            hold2 = max(hold2, release1-i);
            release1 = max(release1, hold1+i);
            hold1 = max(hold1, -i);
        }
        return release2;
    }
    /*
    int maxProfit(vector<int>& prices) {
        prices.push_back(0);
        int mostprof = 0, secmostprof = 0, n = prices.size();
        int last = 0, prof = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] < prices[i-1]){
                prof = prices[i-1] - prices[last];
                if(prof > mostprof){
                    secmostprof = mostprof;
                    mostprof = prof;
                }else if(prof > secmostprof){
                    secmostprof = prof;
                }
                last = i;
            }
        }
        return mostprof + secmostprof;
    }*/
};