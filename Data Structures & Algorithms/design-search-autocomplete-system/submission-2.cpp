class AutocompleteSystem {
public:

    vector<string> sentences;
    vector<int> times;
    int pos;
    string cur;

    map<pair<char,string>,int> freq;

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        this->sentences = sentences;
        this->times = times;
        pos = 0;
        populate();
    }

    void populate()
    {
        freq.clear();

        for(int i=0;i<(int)sentences.size();i++)
        {
            freq[{sentences[i][0],sentences[i]}] += times[i];
        }
    }
    
    vector<string> input(char c) {

        if(c=='#') {pos = 0 ; sentences.push_back(cur) ; times.push_back(1) ; populate() ; cur = "" ; return {};}

        cur += c;

        auto cmp = [](const pair<int,string>& a, const pair<int,string>& b) {
        if (a.first != b.first) return a.first < b.first;   // bigger int on top
        return a.second > b.second;                          // smaller string on top
        };
        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp)> pq(cmp);

        vector<pair<char,string>> toErase;
        vector<pair<pair<char,string>,int>> toInsert;

        for(const auto &[par,f] : freq)
        {
            const auto &[ch,st] = par;
            toErase.push_back(par);              // every entry leaves this generation

            if(ch != c) continue;

            pq.push({f,st});
            if(pos+1 < (int)st.length())
                toInsert.push_back({{st[pos+1], st}, f});
        }

        for(auto &k : toErase) freq.erase(k);
        for(auto &[k,v] : toInsert) freq[k] = v;

        pos++;

        vector<string> ans;
        int cnt = 3;

        while(!pq.empty() && cnt)
        {
            auto [f,st] = pq.top();
            pq.pop();

            ans.push_back(st);
            cnt--;
        }

        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
