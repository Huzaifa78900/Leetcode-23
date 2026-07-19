class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int result = 0;
        int sign = 1;

        while (index < s.size() && s[index] == ' ')
            index++;

        
        if (index < s.size()) {
            if (s[index] == '-') {
                sign = -1;
                index++;
            }
            else if (s[index] == '+') {
                index++;
            }
        }

        
        while (index < s.size() && isdigit(s[index])) {
            int digit = s[index] - '0';

            // Check if adding this digit will overflow
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && digit > 7)) {

                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            result = result * 10 + digit;
            index++;
        }

        return result * sign;
    }
};