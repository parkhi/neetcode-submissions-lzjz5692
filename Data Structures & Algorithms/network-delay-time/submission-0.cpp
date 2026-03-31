class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int, int>>> adj(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n , INT_MAX);
        int mintime = 0;
        int totalnodes = 0;

        for(auto i : times) {
           // cout << "i[0] "<<i[0]<<" {i[1], i[2]} " <<i[1]<<" "<<i[2]<<endl;
            adj[i[0]].push_back({i[1], i[2]});
        }

        dist[k-1] = 0;
        pq.push({0 , k});
        
        while(!pq.empty()) {
            auto elem = pq.top();
            pq.pop();

            int time = elem.first;
            int node = elem.second;

            if(dist[node-1] < time) {
                cout<<"no need to process node  "<<node<<" time is "<<time<<endl;
                continue;
            }

            mintime = max(mintime, time);
            totalnodes++;

            cout << "current node is "<<node <<" total nodes "<<totalnodes<<endl; 

            for( auto nei : adj[node]) {
                int newtime = time + nei.second;
                int neinode = nei.first;
                
                cout <<"neinode "<<neinode<<" newtime "<<newtime<<" dist[neinode] "<<dist[neinode-1]<<endl;

                if(dist[neinode-1] > newtime) {
                    dist[neinode-1] = newtime;
                    pq.push({newtime, neinode});
                }
            }
        }

        if(totalnodes == n) {
            return mintime;
        }
        else {
            return -1;
        }

    }
};
