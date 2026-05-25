class Solution {
public:

    bool helper(int& front, int back) {

        // Base case
        if (back == 0) {
            return true;
        }

        // Recurse till last digit
        if (!helper(front, back / 10)) {
            return false;
        }

        // Compare front and back digits
        if ((front % 10) != (back % 10)) {
            return false;
        }

        // Move front forward
        front /= 10;

        return true;
    }

    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        int front = x;

        return helper(front, x);
    }
};