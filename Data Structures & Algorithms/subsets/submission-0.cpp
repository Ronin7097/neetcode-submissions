class Solution {
   void util(vector<vector<int>> & ans,int i,vector<int> & nums,vector<int> v)
    {
        if(i==nums.size())
        {
            ans.push_back(v);
            return;
        }
        util(ans,i+1,nums,v);
        v.push_back(nums[i]);
        util(ans,i+1,nums,v);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        util(ans,0,nums,v);
        return ans;
    }
};
