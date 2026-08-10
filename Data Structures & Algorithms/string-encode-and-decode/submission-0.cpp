class Solution {
public:

    string encode(vector<string>& strs) {
        string str="";
        for(const string &st:strs)
            str+=st+"|";
        return str;
    }

    vector<string> decode(string s) {
        string temp="";
        cout<<s<<endl;
        vector<string> str;
        for(char &ch : s)
        {
            temp+=ch;
            if(ch=='|')
            {
                temp.pop_back();
                str.push_back(temp);
                temp="";
            }
        }
       // str.pop_back();
        return str;
    }
};
