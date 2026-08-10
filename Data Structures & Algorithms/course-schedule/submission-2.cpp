class Solution {
    vector<bool> dfs,vis;
    vector<vector<int>> g;
    int n;
    bool cyclic(int node)
    {
        dfs[node]=true;
        vis[node]=true;
        bool temp=false;
        for(int &i:g[node])
        {
            if(!vis[i])
            temp |=cyclic(i);
            else if(vis[i] && dfs[i])
            return true;
        }
        dfs[node]=false;
        return temp;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        g=vector<vector<int>>(n);
        int m=prerequisites.size();
        for(int i=0;i<m;i++)
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vis=vector<bool>(n,false);
        dfs=vector<bool>(n,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false){
            bool chk=cyclic(i);
            if(chk)
            return false;
            }
        }
        return true;
    }
};
