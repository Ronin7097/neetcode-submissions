class Solution {
    int x_dir[4]={0,1,0,-1};
    int y_dir[4]={1,0,-1,0};
    int n,m;
    vector<vector<int>> vis;
    int dfs(vector<vector<int>>& g,int nx,int ny)
    {
        vis[nx][ny]=true;
        int count=0;
        for(int i=0;i<4;i++)
        {
            int x=nx+x_dir[i],y=ny+y_dir[i];
            if(x<n && x>=0 && y<m && y>=0 && !vis[x][y] && g[x][y]==1)
            count+=dfs(g,x,y)+1;
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vis=vector<vector<int>>(n,vector<int>(m,false));
        int area=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(vis[i][j]==false && grid[i][j]==1)
                area=max(dfs(grid,i,j)+1,area);
        }
        return area;
    }
};
