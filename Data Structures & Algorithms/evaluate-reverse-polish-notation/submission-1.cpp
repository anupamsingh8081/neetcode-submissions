class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    int n=tokens.size();
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(tokens[i]=="+")
        {
int b=st.top();
st.pop();
int a=st.top();
st.pop();
a+=b;
st.push(a);
        }
        else if(tokens[i]=="-")
        {
int b=st.top();
st.pop();
int a=st.top();
st.pop();
a-=b;
st.push(a);
        }
        else if(tokens[i]=="*")
        {
int b=st.top();
st.pop();
int a=st.top();
st.pop();
a*=b;
st.push(a);
        }
        else if(tokens[i]=="/")
        {
int b=st.top();
st.pop();
int a=st.top();
st.pop();
a/=b;
st.push(a);
        }
        else{
            string a=tokens[i];
            int val=0;
            bool fg=false;
            for(int i=0;i<a.size();i++)
            {if(a[i]=='-')
            {
                fg=true;
                continue;
            }
                val*=10;
                val+=(a[i]-'0');
            }
            if(fg)val*=-1;
            st.push(val);
        }
    }


    return st.top();   
    }
};
