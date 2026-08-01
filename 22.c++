class Solution {
public:
    vector<string> ans;

    void solve(string s, int open, int close, int n) {
        // If we've used all parentheses, store the result.
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add an opening bracket if we still have some left.
        if (open < n) {
            solve(s + "(", open + 1, close, n);
        }

        // Add a closing bracket only if it keeps the string valid.
        if (close < open) {
            solve(s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};