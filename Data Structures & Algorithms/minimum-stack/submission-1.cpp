class MinStack {
public:
stack<int>st;
stack<int>stmin;
int mini=INT_MIN;
    MinStack() {
        
    }
    
    void push(int val) {
     st.push(val);   
    val=min(val,stmin.empty()?val:stmin.top());
    stmin.push(val);
    }
    
    void pop() {
        st.pop();
        stmin.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stmin.top();
    }
};
