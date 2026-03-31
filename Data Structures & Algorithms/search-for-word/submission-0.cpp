class Solution {
    bool res = false;

    void backtrack(vector<vector<char>>& board, string word, string cur, int x, int y) {
         cout<< "cur is first line"<<cur<<endl;

        if(cur == word) {
            res = true;
            return;
        }

        if( x <0 || y < 0 || x >= board.size() || 
            y >= board[0].size() || cur.size() >= word.size() ||
            board[x][y] == '#') {
            return;
        }
        
        char temp = board[x][y];
         cout<< "temp is "<<temp<<endl;
        cur += temp;
         cout<< "cur is temp"<<cur<<endl;
        board[x][y] = '#';

        backtrack(board, word, cur, x+1, y);
        backtrack(board, word, cur, x, y+1);
        backtrack(board, word, cur, x-1, y);
        backtrack(board, word, cur, x, y-1);

        board[x][y] = temp;
        cur.pop_back();    

    }
public:    
    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                string cur = "";
                 cout<< "i j is nex "<<i<<" "<<j<<endl;
                backtrack(board, word, cur, i, j);
                // cout<< "cur is nex "<<cur<<endl;
                if (res) return true;
            }
        }
        return res;
    }
};
