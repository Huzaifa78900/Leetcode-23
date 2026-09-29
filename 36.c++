class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Check all cells
        for (int i = 0; i < 9; i++) {
            
            for (int j = 0; j < 9; j++) {
                
                // Ignore empty cells
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '0';

                // Check row
                for (int k = 0; k < 9; k++) {
                    if (k != j && board[i][k] == board[i][j]) {
                        return false;
                    }
                }

                // Check column
                for (int k = 0; k < 9; k++) {
                    if (k != i && board[k][j] == board[i][j]) {
                        return false;
                    }
                }

                // Find starting position of 3x3 box
                int startRow = (i / 3) * 3;
                int startCol = (j / 3) * 3;

                // Check 3x3 box
                for (int r = startRow; r < startRow + 3; r++) {
                    for (int c = startCol; c < startCol + 3; c++) {
                        
                        if ((r != i || c != j) &&
                            board[r][c] == board[i][j]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
