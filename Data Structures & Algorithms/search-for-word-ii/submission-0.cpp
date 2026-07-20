class Solution {
public:
bool fun(int i,int j,int k,string& word,vector<vector<char>>& board,vector<vector<int>>&vis)
{
    int l=word.size();
    if(k==l)return true;
    int n=board.size();
    int m=board[0].size();
int rrow[]={-1,0,0,1};
int ccol[]={0,-1,1,0};
for(int h=0;h<4;h++)
{
    int r=i+rrow[h];
    int c=j+ccol[h];
    if(r>=0&&c>=0&&r<n&&c<m&&!vis[r][c]&&board[r][c]==word[k])
    {
        vis[r][c]++;
        if(fun(r,c,k+1,word,board,vis)){vis[r][c]=0;
        return true;}
        vis[r][c]=0;
    }
}

return false;

}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string>ans;
    int n=board.size();
    int m=board[0].size();
    vector<vector<pair<int,int>>>arr(26);
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                char ch=board[i][j];
                ch-='a';
                arr[ch].push_back({i,j});
            }}
    for(auto it:words)
    {bool fg=false;
    int p=it[0]-'a';
        for(int h=0;h<arr[p].size();h++){
            int i=arr[p][h].first;
            int j=arr[p][h].second;
            vis[i][j]++;
    if(fun(i,j,1,it,board,vis))
    fg=true;
    vis[i][j]=0;
            if(fg)break;
        }
        if(fg)ans.push_back(it);
    }
    return ans;
    }
};
