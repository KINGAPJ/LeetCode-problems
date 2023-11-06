class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i = 0, n = arr.size(), currInd = 0, wins = 0, maxElem = arr[0];
        while(i < n){
            if(i == currInd)
                i++;
            if(i < n){
                maxElem = max(maxElem, arr[i]);
                if(arr[currInd] > arr[i]){
                    wins++;
                }else{
                    currInd = i;
                    wins = 1;
                }
                if(wins == k){
                    return arr[currInd];
                }
            }
            i++;
        }
        return maxElem;
    }
};