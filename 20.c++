class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        for (char ch : s) {
            // Store every opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                brackets.push(ch);
            }
            else {
                // A closing bracket without an opening one
                if (brackets.empty()) {
                    return false;
                }

                char open = brackets.top();

                // Check if the current closing bracket matches
                if ((ch == ')' && open == '(') ||
                    (ch == '}' && open == '{') ||
                    (ch == ']' && open == '[')) {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }

        // Valid only if no unmatched opening brackets remain
        return brackets.empty();
    }
};