class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto &c : tasks) freq[c-'A']++;

        //vector<int> ans;

        priority_queue< pair< pair<int,int>,int >,vector<pair<pair<int,int>,int>>,decltype([]
        (const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b)
        {
            if(a.first.first!=b.first.first) return a.first.first > b.first.first;
            return a.first.second < b.first.second;
        })
        > pq;

        for(int i=0;i<26;i++)
        {
            if(freq[i]) pq.push({{0,freq[i]},i});
        }

        int idx = 0;

        while(!pq.empty())
        {
            auto [x,c] = pq.top();
            auto [i,f] = x;
            
            if(i<=idx) pq.pop();
            else
            {
                idx++;
                continue;
            }

            idx++;

            if(f>1)
            {
                pq.push({{i+n+1,f-1},c});
            }
        }

        return idx;
    }
};
