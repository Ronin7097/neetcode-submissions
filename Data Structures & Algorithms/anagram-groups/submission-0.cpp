class Solution {
    vector<int> setmaker(const string &str)
    {
        vector<int> n(26);
        for(char ch:str)
        n[ch-'a']++;
        return n;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string> >mp;
        for(string s:strs)
            mp[setmaker(s)].push_back(s);

        vector<vector<string>> ans;
        for(auto i:mp)
        ans.push_back(i.second);
        return ans;
    }
};
