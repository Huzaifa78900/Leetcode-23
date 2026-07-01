class Solution {
public:
    vector<vector<int>> memo;

    bool dfs(int i, int j, string &s, string &p) {
        if (memo[i][j] != -1)
            return memo[i][j];

        // If we've reached the end of the pattern,
        // the string should also be finished.
        if (j == p.size())
            return memo[i][j] = (i == s.size());

        bool currentMatch = false;
        if (i < s.size()) {
            currentMatch = (s[i] == p[j] || p[j] == '.');
        }

        // Check if the next character is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {

            // Skip the current character and '*'
            bool skip = dfs(i, j + 2, s, p);

            // Match one character and continue using the same pattern
            bool take = false;
            if (currentMatch)
                take = dfs(i + 1, j, s, p);

            return memo[i][j] = (skip || take);
        }

        // Normal character match
        if (currentMatch)
            return memo[i][j] = dfs(i + 1, j + 1, s, p);

        return memo[i][j] = false;
    }

    bool isMatch(string s, string p) {
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(0, 0, s, p);
    }
};