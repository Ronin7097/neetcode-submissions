#define INF 2147483647
class Solution {
    vector<vector<bool>> vis;
    int n,m;
    int x_dir[4]={0,0,1,-1};
    int y_dir[4]={1,-1,0,0};
    void bfs(int nodei,int nodej,vector<vector<int>> & grid)
    {
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==0)
                q.push({i,j});
        while(!q.empty())
        {
            auto &[a,b]=q.front();
            vis[a][b]=true;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=a+x_dir[i];
                int y=b+y_dir[i];
                if(x>=0 && x<n && y<m && y>=0 && !vis[x][y] && grid[x][y]>0){
                grid[x][y]=min(grid[x][y],grid[a][b]+1);
                q.push({x,y});
                }
            }
        }
    }
    
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vis=vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(vis[i][j]==false && grid[i][j]==0)
                bfs(i,j,grid);
    }
};
