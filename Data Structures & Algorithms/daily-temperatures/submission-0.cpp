class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    vector<int>ans(n,0);
    stack<pair<int,int>>st;
    for(int i=n-1;i>=0;i--)
    {int v=temperatures[i];
        while(!st.empty()&&st.top().first<=v)
        st.pop();
if(!st.empty())
ans[i]=st.top().second-i;
st.push({v,i});
    }

    return ans; 
    }
};
