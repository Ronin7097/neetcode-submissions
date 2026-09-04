class Solution {
public:
    int kth(vector<int>& a, vector<int>& b, int k) {
        int lo = -1e6, hi = 1e6, res = 0;
        while (lo <= hi) {
            int m = lo + (hi - lo) / 2;
            int cnt = (upper_bound(a.begin(), a.end(), m) - a.begin())
                    + (upper_bound(b.begin(), b.end(), m) - b.begin());
            if (cnt >= k) res = m, hi = m - 1;
            else lo = m + 1;
        }
        return res;
    }

    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size() + b.size();
        if (n % 2) return kth(a, b, (n + 1) / 2);
        return (kth(a, b, n / 2) + kth(a, b, n / 2 + 1)) / 2.0;
    }
};