int di[]={1,0,-1,0};
int dj[]={0,1,0,-1};
bool f(int i,int j,int val,vector<vector<int>>& g)
{
    if(i<0 || j<0 || i>=g.size() || j>=g[0].size()) return false;
    if( g[i][j]<=val) return false;
    return true;
}
int dfs(int i,int j,int &ans,vector<vector<int>>& dis,vector<vector<int>>& g)
{
    //v[i][j]=1;
    //ans=max(ans,d);
    if(dis[i][j]!=0) return dis[i][j];
    for(int k=0;k<4;k++)
    {
        int td=0;
        int x=i+di[k];
        int y=j+dj[k];
        if(f(x,y,g[i][j],g))
        {
            td=dfs(x,y,ans,dis,g);
        }
        dis[i][j]=max(dis[i][j],td+1);
    }
    //v[i][j]=0;
    return dis[i][j];
}
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>> v(n,vector<int> (m,0));
        vector<vector<int>> dis(n,vector<int> (m,0));
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dis[i][j]==0){
                   ans=max(ans, dfs(i,j,ans,dis,g));
                }
            }
        }
        return ans;
    }
};