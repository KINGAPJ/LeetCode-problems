class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size(), currInd = 0, wins = 0, maxElem = arr[0];
        for(int i = 0; i < n; i++){
            if(i == currInd)
                i++;
            if(i < n){
                maxElem = max(maxElem, arr[i]);
                if(arr[currInd] > arr[i])
                    wins++;
                else{
                    currInd = i;
                    wins = 1;
                }
                if(wins == k)
                    return arr[currInd];
            }
        }
        return maxElem;
    }
};