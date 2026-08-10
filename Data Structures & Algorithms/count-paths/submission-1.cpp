class Solution {
    int dfs(int x,int y,vector<vector<int>> &dp)
    {
        if(x==0 && y==0)
        return 1;
        if(dp[x][y]!=-1)
        return dp[x][y];
        if(x==0)
        return dp[x][y]=dfs(x,y-1,dp);
        if(y==0)
        return dp[x][y]=dfs(x-1,y,dp);
        return dp[x][y]=(dfs(x-1,y,dp)+dfs(x,y-1,dp));
    }
public:
    int uniquePaths(int m, int n) {
     vector<vector<int>> dp(m,vector<int>(n, -1));
        return dfs(m-1,n-1,dp);
    }
};
