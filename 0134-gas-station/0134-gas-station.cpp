class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, opt = 0;
        for(int i = 0; i < n; i++)
            sum += (gas[i] - cost[i]);
        if(sum < 0)
            return -1;
        sum = 0;
        for(int i = 0; i < n; i++){
            if(sum < 0){
                opt = i;
                sum = 0;
            }
            sum += (gas[i] - cost[i]);
        }
        return opt;
    }
};