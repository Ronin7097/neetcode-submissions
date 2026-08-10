class Solution {
    int dis(int x1,int y1,int x2,int y2) {return (abs(x1-x2)+abs(y1-y2));}
    class dsu
    {
        public :
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int,int,int>> v;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i)
                continue;
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                v.push_back({dis(x1,y1,x2,y2),i,j});
            }
        }
        sort(v.begin(),v.end());
        dsu d(n);
        int m=v.size(),sum=0;
        for(int i=0;i<m;i++)
        {
            auto & [dis,a,b]=v[i];
            if(d.find(a)!=d.find(b))
            {
                d.unionSet(a,b);
                sum+=dis;
            }
        }
        return sum;
    }
};
