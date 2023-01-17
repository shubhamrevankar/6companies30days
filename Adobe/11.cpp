//2034. Stock Price Fluctuation
class StockPrice {
public:
    unordered_map<int,int> m;
    set<pair<int,int>> s;
    int latest,time;
    StockPrice() {
        time=0;
    }
    
    void update(int timestamp, int price) {
        if(m[timestamp]!=0){
            if(s.find({m[timestamp],timestamp}) != s.end())
                s.erase(s.find({m[timestamp],timestamp}));
        }
        s.insert({price,timestamp});
        m[timestamp]=price;
        if(timestamp>=time) {latest=price;time=timestamp;}
    }
    
    int current() {
        return latest;
    }
    
    int maximum() {
        return s.rbegin()->first;
    }
    
    int minimum() {
        return s.begin()->first;
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