class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));

        place(board, 0, n, n);

        return res;
    }

    void place(vector<vector<char>>& board, int r, int n, int left) {
        if (left == 0) {
            valid(board, n);
            return;
        }
        if (r >= n) return;

        for (int i = 0; i < n; i++) {
            if (board[r][i] == '.') {
                vector<vector<char>> oldBoard = board;
                kill(board, r, i, 'K', n);
                board[r][i] = 'Q';
                place(board, r + 1, n, left - 1);
                board = oldBoard;
            }
        }
    }    

    void kill(vector<vector<char>>& board, int r, int c, char ch, int n) {
        for (int i = 0; i < n; i++)
            board[r][i] = ch;
        for (int i = 0; i < n; i++)
            board[i][c] = ch;
        for (int i = 0; (r + i < n) && (c + i < n); i++)
            board[r + i][c + i] = ch;
        for (int i = 0; (r - i >= 0) && (c - i >= 0); i++)
            board[r - i][c - i] = ch;
        for (int i = 0; (r + i < n) && (c - i >= 0); i++)
            board[r + i][c - i] = ch;
        for (int i = 0; (r - i >= 0) && (c + i < n); i++)
            board[r - i][c + i] = ch;
    }

    void valid(vector<vector<char>>& board, int n) {
        vector<string> sol;
        for (int i = 0; i < n; i++) {
            string cur;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'K')
                    cur += '.';
                else
                    cur += board[i][j];
            }
            sol.push_back(cur);
        }
        res.push_back(sol);
    }
};

