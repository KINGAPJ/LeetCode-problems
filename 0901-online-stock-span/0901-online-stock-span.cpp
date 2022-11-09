class StockSpanner {
public:
    StockSpanner() {
    }
    stack<pair<int, int>> s;
    int next(int price) {
        int ans = 1;
        while (!s.empty() && s.top().first <= price) {
            ans += s.top().second;
            s.pop();
        }
        s.push({price, ans}); //index can't be pushed.. refer first example.. we can 
        //      put the effect of popping in the index as 'ans'
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */