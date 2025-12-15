class Solution {
public:
    bool isPalindrome(int x) {
        long long int n, t, y = 0;
        t = x;
        if (x < 0) {
            return (0);
        }
        while (x > 0) {
            n = x % 10;
            x /= 10;
            y = y * 10 + n;
        }
        if (y <= 2, 147, 483, 647 && y >= -2, 147, 483, 648) {
            if (y == t) {
                return (1);
            }
            return (0);
        }
        return 0;
    }
};