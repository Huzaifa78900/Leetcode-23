class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        vector<string> zigzag(numRows);

        int row = 0;
        int direction = 1; // 1 = down, -1 = up

        for (int i = 0; i < s.size(); i++) {
            zigzag[row] += s[i];

            if (row == 0)
                direction = 1;
            else if (row == numRows - 1)
                direction = -1;

            row += direction;
        }

        string result = "";

        for (int i = 0; i < numRows; i++) {
            result += zigzag[i];
        }

        return result;
    }
};