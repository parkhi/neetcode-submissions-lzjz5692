class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if ((i==0 || i==row-1 || j==0 || j==col-1) && board[i][j] == 'O') {
                    dfs(board, i, j, row, col);
                }
            }
        }

         for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                //cout << board[i][j] <<" ";
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
            //cout <<endl;
         }
    }

    void dfs(vector<vector<char>>& board, int i, int j, int row, int col) {
        if(i<0 || i>=row || j<0 || j>=col || board[i][j] == '#') {
            return;
        }

        board[i][j] = '#';

        vector<pair<int,int>> dir = {{1,0} , {0,1} , {-1,0} , {0,-1}};

        for(int k=0; k<4; k++) {
            int r = i+dir[k].first;
            int c = j+dir[k].second;

            if(r>=0 && r<row && c>=0 && c<col && board[r][c] == 'O') {
                dfs(board, r, c, row, col);
            }
        }
    }
};
