class Solution {
    vector<int> vis;
    vector<vector<int>> g;
    void dfs(int node)
    {
        vis[node]=true;
        for(int&i: g[node])
        {
            if(vis[i]==false)
            dfs(i);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        g= vector<vector<int>>(n);
        vis= vector<int>(n,false);
        for(int i=0;i<edges.size();i++){
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false){
            count++;
            dfs(i);
            }
        }
        return count;
    }
};
