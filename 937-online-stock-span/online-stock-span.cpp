class StockSpanner {
public:
    stack<pair<int,int>> stocks;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int freq=1;
        while(!stocks.empty() && stocks.top().first<=price){
            freq+=stocks.top().second;
            stocks.pop();
        }
        stocks.push({price,freq});
        return freq;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */