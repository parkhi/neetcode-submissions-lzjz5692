class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj(n);
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
                        //  cost, dest, stops
        for(auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});            
        }

        vector<vector<int>> dist(n, vector<int>(k+2,INT_MAX));
        dist[src][0] = 0;
        pq.push({0, src, -1});

        while(!pq.empty()) {
            auto [wt, u, stop] = pq.top();
            cout<<"[wt, u, stop] "<<wt<<" "<<u<<" "<<stop<<endl;

            pq.pop();
            if(u == dst) return wt;

            if(stop == k) {
                continue;
            }
            for(auto [v, wht] : adj[u]) {
                int newwt = wht+wt;
                if(newwt < dist[v][stop+1]) {
                    cout<<"u v newwt dist[v][stop+1]  "<<u<<" "<<v<<" "<<newwt<<" "<<dist[v][stop+1]<<endl;
                    dist[v][stop+1] = newwt;
                    pq.push({newwt, v, stop+1});
                }
            }

        }

        return -1 ;
    }
};
