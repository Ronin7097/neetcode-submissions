class Solution {
    int x_dir[4]={0,0,-1,1};
    int y_dir[4]={1,-1,0,0};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>> visa(n,vector<bool>(m,false)),visp(n,vector<bool>(m,false));
        queue<pair<int,int>> qp,qa;
        vector<vector<int>> ans;
        vector<vector<pair<char,char>>> chk(n,vector<pair<char,char>>(m,make_pair('\0','\0')));
        for(int i=0;i<m;i++)
        {
            chk[0][i].first='p';
            chk[n-1][i].second='a';
            qp.push({0,i});
            qa.push({n-1,i});
            visp[0][i]=true;
            visa[n-1][i]=true;
        }
        for(int i=0;i<n;i++)
        {
            chk[i][0].first='p';
            chk[i][m-1].second='a';
            qp.push({i,0});
            qa.push({i,m-1});
            visp[i][0]=true;
            visa[i][m-1]=true;
        }
        while(!qp.empty())
        {
            auto &[i,j]=qp.front();
            qp.pop();
            visp[i][j]=true;
            for(int a=0;a<4;a++)
            {
                int x=i+x_dir[a];
                int y=j+y_dir[a];
                if(x>=0 && x<n && y>=0 && y<m)
                {
                    if(heights[x][y]>=heights[i][j]){
                    if(!visp[x][y])
                    qp.push({x,y});
                    if(chk[x][y].first!='p')
                    chk[x][y].first=chk[i][j].first;
                    // if(chk[x][y].second!='a')
                    // chk[x][y].second=chk[i][j].second;
                 }
                }
            }
        }
        while(!qa.empty())
        {
            auto &[i,j]=qa.front();
            qa.pop();
            visa[i][j]=true;
            for(int a=0;a<4;a++)
            {
                int x=i+x_dir[a];
                int y=j+y_dir[a];
                if(x>=0 && x<n && y>=0 && y<m)
                {
                    if(heights[x][y]>=heights[i][j]){
                    if(!visa[x][y])
                    qa.push({x,y});
                    // if(chk[x][y].first!='p')
                    // chk[x][y].first=chk[i][j].first;
                    if(chk[x][y].second!='a')
                    chk[x][y].second=chk[i][j].second;
                 }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(chk[i][j].first=='p' && chk[i][j].second=='a')
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};
