class Solution {
    vector<bool> vis;
    vector<vector<int>> g;
    void dfs(int node)
    {
        vis[node]=true;
        for(int &i:g[node])
        {
            if(vis[i]==false)
            dfs(i);
        }
    }
    class dsu
    {
        public:
        vector<int> parent;
        dsu(int n)
        {
            parent=vector<int>(n);
            for(int i=0;i<n;i++)
            parent[i]=i;
        }
        int find(int i)
        {
            while(i!=parent[i])
            i=parent[i];
            return i;
        }

        void unionSet(int a,int b)
        {
            int x=find(a);
            int y=find(b);
            parent[x]=y;
        }
    };
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vis=vector<bool>(n,false);
        g=vector<vector<int>>(n);
        int m=edges.size();
        dsu d(n);
        for(int i=0;i<m;i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
            if(d.find(edges[i][0])==d.find(edges[i][1]))
            return false;
            d.unionSet(edges[i][0],edges[i][1]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                dfs(i);
                count++;
            }
        }
        if(count>1)
        return false;
        return true;
    }
};
