class Solution {
    string setmaker(const string &str)
    {
        vector<int> n(26);
        for(char ch:str)
        n[ch-'a']++;

        string ne;


    for (int i = 0; i < 26; i++) {
    for (int j = 0; j < n[i]; j++) {
        ne += ('a' + i);
    }
}
return ne;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> >mp;
        for(string s:strs)
            mp[setmaker(s)].push_back(s);

        vector<vector<string>> ans;
        for(auto i:mp)
        ans.push_back(i.second);
        return ans;
    }
};
