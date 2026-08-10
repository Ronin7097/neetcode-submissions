class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_left=0,max_right=prices.size()-1;
        int l=0,r=prices.size()-1;
        while(l<prices.size() && r>=0)
        {
            if(prices[min_left]>prices[l] && l<max_right)
                min_left=l;
            if(prices[max_right]<prices[r] && min_left<r)
            max_right=r;
            l++;
            r--;
        }
        cout<<prices[max_right]<<" "<<min_left<<endl;
        if((prices[max_right]-prices[min_left])>=0)return (prices[max_right]-prices[min_left]);
        return 0;
    }
};
