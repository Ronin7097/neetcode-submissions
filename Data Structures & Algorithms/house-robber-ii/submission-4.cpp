class Solution {
    int rob_help(vector<int> & nums,int i,int j)
    {
        vector<int> dp(nums.size()+1,0);
        dp[i]=nums[i];
        dp[i+1]=max(dp[i],nums[i+1]);
        for(int a=i+2;a<=j;a++)
        dp[a]=max(nums[a]+dp[a-2],dp[a-1]);
        return dp[j];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
        return nums[0];
        return max(rob_help(nums,0,n-2),rob_help(nums,1,n-1));
    }
};
