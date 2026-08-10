class Solution {
    // 0-buy
    // 1-sell
    int dfs(vector<int> &prices,int chk,int i)
    {
        if(i>=prices.size())
        return 0;
        int n=prices.size();
        int temp=INT_MIN;
        if(chk==0)
        {
            for(int j=i;j<n;j++)
            temp=max(temp,dfs(prices,1,j+2)+prices[j]);
        }
        else
        {
            for(int j=i;j<n;j++)
            temp=max(temp,dfs(prices,0,j+1)-prices[j]);
        }
        return temp;
    }
public:
    int maxProfit(vector<int>& prices) {

        int temp=INT_MIN;
        int n=prices.size();
        for(int i=0;i<n;i++)
            temp=max(temp,dfs(prices,0,i+1)-prices[i]);
        return temp<0?0:temp;

    }
};
