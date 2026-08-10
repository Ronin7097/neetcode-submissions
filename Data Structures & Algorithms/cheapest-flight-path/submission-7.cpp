class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX);
        prices[src]=0;
        int m=flights.size();
        for(int i=0;i<=k;i++)
        {
        vector<int> temp(prices.begin(),prices.end());
           for(int j=0;j<m;j++)
           {
             int s=flights[j][0];
             int p=flights[j][2];
             int d=flights[j][1];
             if(prices[s]==INT_MAX)
             continue;
             if(temp[d]>prices[s]+p)
             temp[d]=prices[s]+p;
           }
           prices=temp;
        }
        return prices[dst]==INT_MAX?-1:prices[dst];
    }
};
