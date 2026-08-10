class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>g(n+1);
        for(const auto& time : times) 
            g[time[0]].push_back({time[1], time[2]});
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto [dist,node]=pq.top();
            pq.pop();
             if (dist > dis[node]) 
                continue;
            for(pair<int,int> & neb: g[node])
            {
                if(dis[neb.first]>dist+neb.second)
                {
                    dis[neb.first]=dist+neb.second;
                    pq.push({dis[neb.first],neb.first});
                }
            }
        }
        int max_delay = 0;
        for(int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) 
                return -1; 
            max_delay = max(max_delay, dis[i]);
        }
        
        return max_delay;
    }
};
