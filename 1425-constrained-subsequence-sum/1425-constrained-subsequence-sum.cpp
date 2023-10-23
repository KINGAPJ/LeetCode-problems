class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int bestSum = 0, currSum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            while(!pq.empty() && pq.top().second < i-k)
                pq.pop();
            if(!pq.empty()){
                auto u = pq.top();
                if(u.first < 0)
                    currSum = 0;
                else{
                    currSum = u.first;
                    bestSum = max(currSum, bestSum);
                }
            }
            currSum += nums[i];
            if(currSum < 0)
                currSum = 0;
            bestSum = max(currSum, bestSum);
            pq.push({currSum, i});
        }
        if(bestSum == 0)
            return *max_element(nums.begin(), nums.end());
        return bestSum;
    }
};