class Solution {
public:

    void helper(int open,
                int close,
                int n,
                string& current,
                vector<string>& result) {

        // Base case:
        // Valid parentheses string formed.
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if still available.
        if (open < n) {
            current.push_back('(');
            helper(open + 1, close, n, current, result);
            current.pop_back();
        }

        // Add ')' only if valid.
        if (close < open) {
            current.push_back(')');
            helper(open, close + 1, n, current, result);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string current;

        helper(0, 0, n, current, result);

        return result;
    }
};