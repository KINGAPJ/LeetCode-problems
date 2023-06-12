class StockPrice {
    map<int, set<int>> price_ts;
    map<int, int> ts_price;
public:
    StockPrice() {}
    void update(int timestamp, int price) {
        price_ts[ts_price[timestamp]].erase(timestamp);
        if(price_ts[ts_price[timestamp]].empty())
            price_ts.erase(ts_price[timestamp]);
        ts_price[timestamp] = price;
        price_ts[price].insert(timestamp);
    }
    int current() {
        return ts_price.rbegin()->second;
    }
    int maximum() {
        return price_ts.rbegin()->first;
    }
    int minimum() {
        return price_ts.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */