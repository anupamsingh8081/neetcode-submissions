class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>>adj(n+1);
    for(auto it:times)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }
    vector<int>dis(n+1,1e8);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,k});
    dis[k]=0;
    while(!q.empty())
    {
        int node=q.top().second;
        int dist=q.top().first;
        q.pop();
        for(auto it:adj[node])
        {
            int adjnode=it.first;
            int t=it.second;
            if(dis[adjnode]>dist+t)
            {
                dis[adjnode]=dist+t;
                q.push({dis[adjnode],adjnode});
            }
        }
    }
    int maxi=0;
    for(int i=1;i<=n;i++)maxi=max(maxi,dis[i]);
    return maxi==1e8?-1:maxi;
    }
};
