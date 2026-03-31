class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, cols[9] = {0}, squares[9] = {0};

        for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                int val = board[i][j]-'1';
                val = 1 << val;

                if((val & rows[i]) || (val & cols[j]) || (val & squares[(i/3)*3+(j/3)]))
                    return false;

                rows[i] |= val;
                cols[j] |= val;
                squares[(i/3)*3+(j/3)] |= val;
            }
        }

        return true;
        
    }
};
