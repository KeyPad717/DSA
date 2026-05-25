class Solution {
public:
    long long myPow(long long x, long long n) {
        long long power = n;

        long long result = 1LL;

        while (power > 0) {
            // If power is odd
            if (power % 2 == 1) {
                result = (result * x) % 1000000007;
            }

            x = (x * x) % 1000000007;
            power /= 2;
        }

        return result % 1000000007;
    }
    int countGoodNumbers(long long n) {
        if(n==1)    return 5;
        if(n==2)    return 20;
        return (myPow(5,(n+1)/2) * myPow(4,n/2)) % 1000000007;
    }
};