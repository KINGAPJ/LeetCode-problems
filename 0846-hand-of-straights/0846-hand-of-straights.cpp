class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize) 
            return 0;
        sort(hand.begin(), hand.end());
        for(int i = 0; i < n; i++){
            if(hand[i] == -1) 
                continue;
            int k = i;
            for(int j = 1; j < groupSize; j++){
                while(k < n && hand[i] + j != hand[k]) 
                    k++;
                if(k == n) 
                    return 0;
                hand[k] = -1;
            }
        }
        return 1;
    }
};