class Solution {
public:
    int minOperations(const string &s) {
        bool isSorted = is_sorted(s.begin(), s.end());

        if (isSorted) {
            return 0;
        }

        int n=s.size();
    
        if (n == 2) {
            return -1;
        }

        char minVal = s[0], maxVal = s[0];
        for (char ch : s) {
            minVal = min(minVal, ch);
            maxVal = max(maxVal, ch);
        }

        if (s[0] == minVal || s[n - 1] == maxVal) {
            return 1;
        }

        for (int i = 1; i + 1 < n; ++i) {
            if (s[i] == minVal || s[i] == maxVal) {
                return 2;
            }
        }

        return 3;
    }
};