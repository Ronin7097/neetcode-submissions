class Solution {
    int digit_counter(int n, vector<char>& chars, int& l) {
        if (n <= 1) return 0;
        string str = to_string(n);
        for (char& i : str) chars[l++] = i;

        return str.size();
    }

   public:
    int compress(vector<char>& chars) {
        int count = 0;
        int l = 0;
        int n = chars.size();
        int temp = 1;
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && chars[i] == chars[i + 1])
                temp++;
            else {
                // cout << temp << endl;
                chars[l++] = chars[i];
                int temporary;
                temporary = digit_counter(temp, chars, l);
                count = count + temporary + 1;
                temp = 1;
            }
        }
        return count;
    }
};