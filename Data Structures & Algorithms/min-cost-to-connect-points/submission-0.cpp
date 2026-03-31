class DSU {
public:
    vector<int> parent, size;

    DSU(int n) : parent(n+1), size(n+1, 1) {
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int find(int node) {
        if(parent[node] != node) {
            parent[node] = find(parent[node]);
        }

        return parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return false;

        if(size[pu] < size[pv]) swap(pu,pv);
        size[pu] += size[pv];
        parent[pv] = pu;

        return true;
    }
};

class Solution {

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        int res = 0;
        vector<vector<int>> edges;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        for(auto elem : edges){
            int dist = elem[0];
            int u = elem[1];
            int v = elem[2];

            if(dsu.unionSets(u, v)) {
                res += dist;
            }
        }

        return res;
    }
};
