class Solution {
public:

    bool isPalindrome(int x) {

        // Negative numbers are not palindrome.
        // Numbers ending with 0 (except 0 itself)
        // are also not palindrome.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse only half of number.
        while (x > reversedHalf) {

            reversedHalf =
                reversedHalf * 10 + x % 10;

            x /= 10;
        }

        // Even digits:
        // x == reversedHalf
        //
        // Odd digits:
        // x == reversedHalf / 10
        return (x == reversedHalf ||
                x == reversedHalf / 10);
    }
};