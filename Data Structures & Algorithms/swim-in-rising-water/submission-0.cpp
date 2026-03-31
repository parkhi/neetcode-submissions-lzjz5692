class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int,int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        pq.push({grid[0][0], 0, 0});
        visit.insert({0, 0});

        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int t = cur[0] , r = cur[1], c = cur[2];
            if(r == n-1 && c== n-1) {
                return t;
            }

            for(auto dir : directions) {
                int neiR = r + dir[0];
                int neiC = c + dir[1];

                if(neiR<0 || neiR==n || neiC<0 || neiC==n ||
                    visit.count({neiR,neiC}))
                        continue;

                visit.insert({neiR, neiC});
                pq.push({max(t, grid[neiR][neiC]), neiR, neiC});
            }
            
        }
        
    }
};
