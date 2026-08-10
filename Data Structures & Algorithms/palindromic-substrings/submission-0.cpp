class Solution {
    string rng(int i,int j){return to_string(i) + ","+ to_string(j);}
public:
    int countSubstrings(string s) {
        unordered_set<string> mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(s[l]==s[r] && l>=0 && r<n){
                mp.insert(rng(l,r));
                l--;
                r++;
            }
            l=i,r=i+1;
            while(s[l]==s[r] && l>=0 && r<n){
                mp.insert(rng(l,r));
                l--;
                r++;
            }
        }
        return mp.size();
    }
};
