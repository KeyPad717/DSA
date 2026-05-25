class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long myPow(long long x, long long n) {
        long long result = 1;

        while (n > 0) {
            if (n & 1) {
                result = (result * x) % MOD;
            }

            x = (x * x) % MOD;
            n >>= 1;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        return (myPow(5, (n + 1) / 2) *
                myPow(4, n / 2)) % MOD;
    }
};