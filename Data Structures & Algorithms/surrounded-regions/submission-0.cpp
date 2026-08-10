class Solution {
    vector<vector<bool>> vis;
    int n,m;
    int x_dir[4]={0,0,-1,1};
    int y_dir[4]={1,-1,0,0};

    void dfs(vector<vector<char>>&board,int nodei,int nodej)
    {
        vis[nodei][nodej]=true;
        board[nodei][nodej]='t';

        for(int i=0;i<4;i++)
        {
            int x=nodei +x_dir[i];
            int y=nodej +y_dir[i];
            if(x>=0 && x<n && y>=0 && y<m)
            {
                if(vis[x][y]==false && board[x][y]=='O')
                dfs(board,x,y);
            }
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        n=board.size(),m=board[0].size();
        vis=vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0]=='O')
            dfs(board,i,0);
            if(!vis[i][m-1] && board[i][m-1]=='O')
            dfs(board,i,m-1);
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i] && board[0][i]=='O')
            dfs(board,0,i);
            if(!vis[n-1][i] && board[n-1][i]=='O')
            dfs(board,n-1,i);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='t')
                board[i][j]='O';
                else if(board[i][j]=='O')
                board[i][j]='X';
            }
        }
    }
};
