class Solution {
public:
    vector<vector<int>> memo;

    int uniquePaths(int m, int n) {
        memo.resize(m, vector<int>(n, -1));
        memo[0][0] = 1;

        return dfs(m-1 , n-1, m, n);
    }

    int dfs(int r, int c, int m , int n) {
        if(r >= m || r < 0 || c>=n || c<0) {
            return 0;
        }
        if(memo[r][c] != -1) {
            return memo[r][c];
        }
        
        memo[r][c] = dfs(r-1,c,m,n) + dfs(r,c-1,m,n);

        return memo[r][c];
    }
};
