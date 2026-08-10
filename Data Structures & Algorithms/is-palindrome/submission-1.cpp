class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
         while (l < r)
{
            cout << tolower(s[l]) << " " << (char)tolower(s[r]) << endl;

    // Move l to the next alphabet character
    while (l < r && (tolower(s[l]) < 'a' || tolower(s[l]) > 'z') && (tolower(s[l]) < '0' || tolower(s[l]) > '9'))
        l++;
    
    // Move r to the previous alphabet character
    while (l < r && (tolower(s[r]) < 'a' || tolower(s[r]) > 'z')&& (tolower(s[r]) < '0' || tolower(s[r]) > '9'))
        r--;
    
    // Now compare characters
    if (tolower(s[l]) != tolower(s[r])) {
        return false;
    }

    // Move both pointers inward
    l++;
    r--;
}
return true;

    }
};
