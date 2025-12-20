class StockSpanner {
public:
    stack<pair<int, int>> st;
    

    StockSpanner() {
        
    }
    
    int next(int price) {
        int index = 0;

        while(!st.empty() && st.top().first <= price){
            index += st.top().second;
            st.pop();
        }

        st.push({price, index + 1});

        return index+1; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */