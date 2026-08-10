class Solution {
    vector<vector<int>> g;
    vector<bool> dfs,vis;
    vector<int> order;
    int n; 
    bool cycle(int node)
    {
        dfs[node]=true;
        vis[node]=true;
        bool temp=false;
        for(int &i:g[node])
        {
            if(!vis[i])
            temp|=cycle(i);
            else if(vis[i] && dfs[i])
            return true;
        }
        dfs[node]=false;
        return temp;
    }

    void topo(int node)
    {
        vis[node]=true;
        for(int &i:g[node])
        {
            if(!vis[i])
            topo(i);
        }
        order.push_back(node);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        int m=prerequisites.size();
        g=vector<vector<int>>(n);
        for(int i=0;i<m;i++)
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vis=vector<bool>(n,false);
        dfs=vector<bool>(n,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            if(cycle(i))
            return {};
        }
        vis=vector<bool>(n,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            topo(i);
        }
        reverse(order.begin(),order.end());
        return order;
    }
};
