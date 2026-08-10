class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]={0},arr2[26]={0};
        for(char ch:s)
        arr[ch-'a']++;
        for(char ch:t)
        arr2[ch-'a']++;

        for(int i=0;i<26;i++)
        if(arr[i]!=arr2[i])
        return false;
    return true;
        
    }
};
