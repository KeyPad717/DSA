class Solution {
public:
    string reverseWords(string s) {
        // 1. Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0;

        // 2. Reverse each word
        for (int j = 0; j <= n; j++) {
            if (j == n || s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }

        // 3. Remove extra spaces
        int write = 0;

        for (int read = 0; read < n; read++) {
            if (s[read] != ' ' ||
                (write > 0 && s[write - 1] != ' ')) {
                s[write++] = s[read];
            }
        }

        // Remove trailing space
        if (write > 0 && s[write - 1] == ' ')
            write--;

        s.resize(write);

        return s;
    }
};