class Solution {
    void util(vector<vector<int>>& ans, int sum, int i, const int& target,
              const vector<int>& candidates, vector<int> v) {
        if (sum >= target || i == candidates.size()) {
            if (target == sum)
                ans.push_back(v);
            return;
        }
        int j=i;
        while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
            i++;
        util(ans, sum, i + 1, target, candidates, v);
        v.push_back(candidates[j]);
        util(ans, sum + candidates[j], j + 1, target, candidates, v);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        util(ans, 0, 0, target, candidates, {});
        return ans;
    }
};