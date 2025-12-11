class MinStack {
public:
    stack<long long>st;
    long long minEle;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minEle = val;
        }
        else if(val < minEle){
            st.push(2LL *val - minEle);
            minEle = val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {

        if(st.top() < minEle){
            minEle = 2*minEle - st.top();
        }

        st.pop();        
    }
    
    int top() {
        if(st.top() < minEle){
            return minEle;
        }
        return st.top();
    }
    
    int getMin() {
        return minEle;
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