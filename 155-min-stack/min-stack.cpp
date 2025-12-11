class MinStack {
private:
        stack<long long> st;
        long long min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            min = val;
            st.push(val);
        } else {
            if(val > min) {
                st.push(val);
            } else {
                st.push(2LL * val - min);
                min = val;
            } 
        }
    }
    
    void pop() {
        if(st.empty()) return st.pop();
        long long x = st.top();
        st.pop();

        if(x < min) min = 2 * min - x;
    }
    
    int top() {
        long long x = st.top();
        if (st.empty()) return st.top();
        if(min < x) return x;
        return min;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */