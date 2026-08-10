class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('-');
        unordered_map<char,char> mp;
        mp['{']='}';
        mp['[']=']';
        mp['(']=')';
        for(int i=0;i<s.size() && !st.empty();i++){
            if(s[i]==mp[st.top()])
            {
                st.pop();
                continue;
            }
        st.push(s[i]);
        }
        if(st.top()=='-')
        return true;
        return false;
    }
};
