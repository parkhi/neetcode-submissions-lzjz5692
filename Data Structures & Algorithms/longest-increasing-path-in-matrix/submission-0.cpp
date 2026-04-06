class Solution {
    vector<vector<int>> memo;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memo.resize(matrix.size(), vector<int>(matrix[0].size(), -1));
        
        int res = 0;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                dfs(matrix, i, j, res);
            }
        }

        return res;

    }

    int dfs(vector<vector<int>>& matrix, int i, int j, int& len) {

        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size()) {
            return 0;
        }
        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        if(i>0 && matrix[i][j] < matrix[i-1][j]) {
            memo[i][j] = max(memo[i][j], 1+dfs(matrix, i-1, j, len));
        }
        if(i<matrix.size()-1 && matrix[i][j] < matrix[i+1][j]) {
            memo[i][j] = max(memo[i][j], 1+dfs(matrix, i+1, j, len));
        }
        if(j>0 && matrix[i][j] < matrix[i][j-1]) {
            memo[i][j] = max(memo[i][j], 1+dfs(matrix, i, j-1, len));
        }
        if(j<matrix[0].size()-1 && matrix[i][j] < matrix[i][j+1]) {
            memo[i][j] = max(memo[i][j], 1+dfs(matrix, i, j+1, len));
        }
        memo[i][j] = max(memo[i][j], 1);
        len = max(len, memo[i][j]);
        return memo[i][j];  

    }
};
