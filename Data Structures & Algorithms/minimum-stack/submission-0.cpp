class MinStack {
public:
vector<int>st;
map<int,int>mp;
    MinStack() {
        
    }
    
    void push(int val) {
     st.push_back(val);   
     mp[val]++;
    }
    
    void pop() {
        int val=st.back();
        mp[val]--;
        if(mp[val]==0)mp.erase(val);
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return (*mp.begin()).first;
    }
};
