class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;
        int min = -1, fresh = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0 ; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
    
    if( !fresh) {
        return 0;
    }

    //cout << "total fresh "<<fresh<<endl;

    vector<vector<int>> dir = {{1,0}, {0,1},{-1,0},{0,-1}};

    while(!q.empty()) {
        int size = q.size();
       // cout << "size " <<size<<endl;
        min++;

        while(size--) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            for(int j=0; j<4; j++) {
                int r = row + dir[j][0];
                int c = col + dir[j][1];

                if( r < 0 || r >= m || c < 0 || c >= n ||
                    grid[r][c] != 1) {
                        continue;
                    }

                grid[r][c] = 2;
                fresh--;
                q.push({r,c});
            }
        }
    }
    if(!fresh) {
        return min;
    }

    return -1;
        
    }
};
