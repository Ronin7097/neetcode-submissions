class Solution {
    unordered_map<int, int> mp;
    void util(vector<vector<int>>& ans, int i, vector<int>& nums,
              vector<int> v) {
        if (i == nums.size()) {
            ans.push_back(v);
            return;
        }
        int j=i;
        while (i < nums.size()-1 && nums[i] == nums[i + 1])
            i++;
        util(ans, i + 1, nums, v);
        v.push_back(nums[j]);
        util(ans, j + 1, nums, v);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        util(ans, 0, nums, v);
        return ans;
    }
};
