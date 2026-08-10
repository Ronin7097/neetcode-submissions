class Solution {
    void util(vector<vector<int>>& ans, int sum, int i, const int& target,
              const vector<int>& candidates, vector<int> v) {
        if (sum >= target || i == candidates.size()) {
            if (target == sum)
                ans.push_back(v);
            return;
        }
        util(ans, sum, i+1, target, candidates, v);
        v.push_back(candidates[i]);
        util(ans, sum + candidates[i], i, target, candidates, v);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        util(ans, 0, 0, target, candidates, {});
        return ans;
    }
};