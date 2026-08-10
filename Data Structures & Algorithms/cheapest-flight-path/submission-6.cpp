class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        int m=flights.size();
        for(int i=0;i<m;i++)
            g[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        vector<int> dis(n,INT_MAX);
        priority_queue<tuple<int,int,int>> pq;
        pq.push({0,src,0});
        while(!pq.empty())
        {
            auto [dist,node,jmp]=pq.top();
            pq.pop();
            if(jmp>k)continue;
            for(auto &neb:g[node])
            {
                if(dis[neb.first]>dist+neb.second )
                {
                    dis[neb.first]=dist+neb.second;
                    pq.push({dis[neb.first],neb.first,jmp+1});
                }
            }
        }
        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};





