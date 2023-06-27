class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        sort(deck.begin(), deck.end(), greater<int>());
        vector<int> ans;
        int n = deck.size();
        for(auto &i: deck){
            if(q.size()){
                int u = q.front();
                q.pop();
                q.push(u);
            }
            q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};