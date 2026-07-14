class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int temp = x;
        long long reverse = 0;

        while (temp != 0) {
            int digit = temp % 10;
            reverse = reverse * 10 + digit;
            temp /= 10;
        }

        return reverse == x;
    }
};