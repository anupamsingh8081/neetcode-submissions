class MinStack {
public:
stack<pair<int,int>>st;
int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
mini=min(mini,val);
    st.push({val,mini});
    }
    
    void pop() {
        st.pop();
        mini=st.empty()?INT_MAX:st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
