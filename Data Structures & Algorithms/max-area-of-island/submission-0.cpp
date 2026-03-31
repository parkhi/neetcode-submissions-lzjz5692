class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& curA) {
        if(i<0 || j<0 || grid.empty()|| i>=grid.size() || j>=grid[0].size()
             || grid[i][j] == 0) {
                return;
            }

        grid[i][j] = 0;
        curA++;
        
        dfs(grid, i+1, j, curA);
        dfs(grid, i-1, j, curA);
        dfs(grid, i, j+1, curA);
        dfs(grid, i, j-1, curA);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxA = 0, curA = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, curA);
                    maxA = max(maxA, curA);
                    curA = 0;
                }
            }
        }

        return maxA;
    }
};
