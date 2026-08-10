class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int check0=0;
        int total=1,n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0){
            check0++;
            if(check0>1)
            return ans;
            continue;
            }
            total*=nums[i];           
        }

        for(int i=0;i<n;i++)
        {
            if(check0==1){
            if(nums[i]==0){
             ans[i]=total;
            return ans;
            }
            continue;
            }
            ans[i]=total/nums[i]; 
        }
        return ans;
    }
};
