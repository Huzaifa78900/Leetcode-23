class Solution {
public:
    void checkPalindrome(string &s, int left, int right, int &start, int &maxLen) {
        int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;

            if (len > maxLen) {
                maxLen = len;
                start = left;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();

        if (n <= 1)
            return s;

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            // Check odd length palindrome
            checkPalindrome(s, i, i, start, maxLen);

            // Check even length palindrome
            checkPalindrome(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};