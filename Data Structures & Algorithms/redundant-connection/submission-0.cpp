class Solution {
    class dsu
    {
        public:
        vector<int> parent;
        dsu(int n)
        {
            parent=vector<int>(n+1);
            for(int i=0;i<=n;i++)
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        int m=edges.size();
        dsu d(m);
        for(int i=0;i<=m;i++)
        {
            if(d.find(edges[i][0])==d.find(edges[i][1]))
                return edges[i];
            d.unionSet(edges[i][0],edges[i][1]);
        }
        return {};
    }
};
