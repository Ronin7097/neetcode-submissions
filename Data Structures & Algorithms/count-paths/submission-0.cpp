class Solution {
    int dfs(int x,int y,int m,int n)
    {
        if(x==0 && y==0)
        return 1;
        if(x==0)
        return dfs(x,y-1,m,n);
        if(y==0)
        return dfs(x-1,y,m,n);
        return dfs(x-1,y,m,n)+dfs(x,y-1,m,n);
    }
public:
    int uniquePaths(int m, int n) {
        return dfs(m-1,n-1,m,n);
    }
};
