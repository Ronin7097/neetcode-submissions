class Solution {
    bool pal(const string& s) {
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void util(vector<vector<string>>& ans, vector<string> v, string s) {
        if (0 == s.size()) {
            ans.push_back(v);
            return;
        }
        for (int j = 1; j <= s.size(); j++) {
            string str = s.substr(0, j);
            if (pal(str)) {
                v.push_back(str);
                util(ans, v, s.substr(j, s.size()));
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        util(ans, {}, s);
        return ans;
    }
};